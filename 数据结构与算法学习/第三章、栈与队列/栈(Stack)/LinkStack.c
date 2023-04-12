#include <stdbool.h>
#include <stdlib.h>

typedef struct LinkNode{
    int data;       //数据域
    struct LinkNode* next;  //指针域 
}*LinkStack,LinkNode;

//创建
void InitSize(LinkStack S){
    S =NULL;        //初始化操作
}

//判空
bool IsEmpty(LinkStack S){
    if (S==NULL)
    {
        return true;
    }else{
        return false;
    }
}
//插入
bool Push(LinkStack S,int x){
    LinkNode* node = (LinkNode*)malloc(sizeof(LinkNode));   //创建操作
    if(!node) return false; //节点创建失败
    node->data = x;
    node->next = S;
    S = node;
    return true;  //创建成功
}

//删除操作
bool Pop(LinkStack S,int *x){
    if(!S) return false;        //栈为空,删除失败
    *x = S->data;               //将被删除元素赋值x
    S = S->next;                //删除栈顶元素
}

bool GetNum(LinkStack S ,int *x){
    if(!S) return false;        //栈为空,删除失败
    *x = S->data;
    return true;
}