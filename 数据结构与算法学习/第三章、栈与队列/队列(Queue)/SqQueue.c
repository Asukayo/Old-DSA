#define MaxSize 50
#include <stdbool.h>

//队列的顺序存储,使用静态数组
//队列的顺序实现是用一块连续的存储单元，并且附设两个指针rear和front

typedef struct SqQueue
{
    int data[MaxSize];  //存放队列元素
    int rear,front;     //尾指针与头指针
}SqQueue;

//常用的基本操作
//创建销毁，增删改查,判空操作
//InitSqQueue(*Q),IsEmpty(*Q),EnQueue(*Q,x),DeQueue(*Q,*x),GetHead(*Q,*x)

//此处队列的头指针指向队头元素,队尾指针指向队尾元素的下一个位置
//默认为循环队列。

void InitQueue(SqQueue *Q){
    Q->front = Q->rear = 0; //初始化时将队头指针和队尾指针都指向同一个元素
}

bool isEmpty(SqQueue *Q){
    if(Q->front == Q->rear){    //当队头元素等于队尾元素时为空
        return true;
    }else{
        return false;
    }
}

//-----------------------对于循环队列判断队列已满的三个方法---------------------------------
//1、此处进行插入之前要先判断队列是否已满,浪费了一个存储空间，由于rear指针指向的是下一个待插入位置
//2、在初始的结构中定义一个size变量,入队时size++，出队时size--，判满条件就是size = MaxSize
//3、在顺序队列的初始结构中定义一个tag标记，当进行入队操作时tag =1 ,当进行出队操作时tag = 0, 判满时就(tag == 1 && Q->rear == Q->front)

bool EnQueue(SqQueue *Q,int x){
    if((Q->rear+1)%MaxSize == Q->front){       
        return false;                        
    }
    Q->data[Q->rear] = x;
    Q->rear = (Q->rear+1)%MaxSize;         //为防止尾指针出现假溢出
    return true;
}

bool DeQueue(SqQueue *Q,int *x){
    if(isEmpty(Q)){
        return false;   //此时队列为空,无队头元素
    }
    *x = Q->data[Q->front];
    Q->front = (Q->front+1)%MaxSize;    //同样防止队头指针出现假溢出
    return true;
}

bool GetHead(SqQueue *Q,int *x){
    if(isEmpty(Q)){
        return false;   //队列为空队列，查询失败
    }
    *x = Q->data[Q->front];
    return true;
}