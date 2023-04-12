#include <stdbool.h>
#include <stdlib.h>
#define MAXSIZE 50        //声明栈的最大长度

//栈是一种特殊的线性表，只能在栈顶进行入栈出栈操作

//---------------顺序栈的实现---------------------

typedef struct 
{
    int data[MAXSIZE];     //用静态数组存放栈中的元素
    int top;          //栈顶指针，初始值为-1
}SqStack;

//初始化操作
void InitStack(SqStack *S){
    S->top = -1;       //初始化栈顶指针
}

//判断栈空的操作
bool StackEmpty(SqStack *S){
    if(S->top == -1){
        return true;

    }else
    {
        return false;   
    }
}
//进栈操作
bool Push(SqStack *S,int x){
    if(S->top == MAXSIZE -1){
        return false;           //栈已满
    }
    //S->data[++S->top] = x     先令top++，再使用top
    S->top = S->top-1;
    S->data[S->top] = x;
    return true;              
}

// 出栈操作
bool Pop(SqStack *S,int *x){
    if(S->top ==-1) return false;   //栈为空
    *x = S->data[S->top];       
    S->top--;
    return true;
}
//读栈顶元素
bool GetTop(SqStack *S,int *x){
    if(S->top ==-1) return false;    //栈为空
    (*x) = S->data[S->top];         //x记录栈顶元素
    return true;
}