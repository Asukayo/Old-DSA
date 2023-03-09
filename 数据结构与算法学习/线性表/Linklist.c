#include <stdlib.h>
//线性表的链式存储
// 优点：1、可以不连续存储，
    
//缺点：会浪费一定的存储空间

// 常用头指针来标识一个单链表，为了操作上的方便，在单链表的第一个结点之前附加一个节点，称为头结点

//-----------带头结点的单链表-------------

typedef struct  LNode{
    int data;//数据域
    struct LNode* next;//指针域
}LNode,*LinkList;


int InitList(LinkList L){
    L = (LNode*)malloc(sizeof(LNode));
    if(L==NULL){//内存空间不足,分配失败
        return 0;
    }
    L->next = NULL; //将头结点初始化为NULL
    return 1;
}//初始化一个带头结点的单链表