#include <stdio.h>
#include <stdbool.h>

//队列的链式存储结构
//一个头指针，一个尾指针，分别指向待删除的队头元素，以及待插入的队尾元素的位置

//队列的链式存储类型描述
//链式队列结点
typedef struct
{
    int data;   //数据域
    LinkNode * next;    //后驱元素指针
}LinkNode;

//真正的链式队列只包含一个头指针与一个尾指针
typedef struct
{
    LinkNode * front , *rear;   //定义的时候不能忘记rear前面的*
}*LinkQueue;

//队列的基本操作（带头结点）

//队列的初始化操作
void InitLinkQueue(LinkQueue L){
    LinkNode * q = (LinkNode*)malloc(sizeof(LinkNode));
    q->next = NULL;
    L->front = q;
    L->rear = q;
}

//判断队列是否为空
bool IsEmpty(LinkQueue L){
    if(L->front == L->rear){
        return true;
    }else{
        return false;
    }
}

//入队操作
bool EnQueue(LinkQueue L,int x){
    LinkNode * p = (LinkNode*)malloc(sizeof(LinkNode));     //创建临时结点
    p->data = x;
    p->next = L->rear->next;    //将队尾指针赋值给新创建的结点
    L->rear->next = p;          //插入队尾
    L->rear = p;
    return true;            
}

//出队操作
bool DeQueue(LinkQueue L,int *x){
    //判断队列是否为空
    if(L->front == L->rear){
        return false;
    }
    LinkNode * p = L->front->next;      //将即将被删除的结点取出
    *x = p->data;                       //将值取出
    L->front->next = p->next;           //将结点删除
    //若队列中只有一个节点，删除之后变为空队列
    if(p == L->rear){
        L->rear = L->front;         //将头尾指针指向头结点
    }
    return true;
}






