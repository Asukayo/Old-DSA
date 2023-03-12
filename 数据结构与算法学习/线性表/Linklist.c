#include <stdlib.h>
//线性表的链式存储
// 优点：1、可以不连续存储，
    
//缺点：会浪费一定的存储空间

// 常用头指针来标识一个单链表，为了操作上的方便，在单链表的第一个结点之前附加一个节点，称为头结点

//-----------带头结点的单链表-------------
//后插插入操作的时间复杂度为O(n)，删除操作的时间复杂度为O(n)
//主要的实践操作都耗费在查找上面，真正对节点插入删除的操作的时间复杂度为O(1)


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

LNode * GetLinkListNode(LinkList L,int i){
    //i是要插入的元素的位序,从一开始
    //首先判断插入的位置是否合法
    if(i<1){
        return NULL;
    }
    LNode *p = L->next;   //定义一个指针元素指向第一个节点(并非头结点)
    int j = 1;      //代表当前节点
    while (p!=NULL && j<i)    //找到所需要查找的节点
    {
        p = p->next;
        j++;
    }
    if(p == NULL){  //以防p因为空节点而跳出上述循环，保证上述循环可以找到真正的i的前驱节点
        return NULL;
    }
    return p;       //查找成功，返回指针p
}//按位序查找结点元素

int ListInsert(LinkList L,int i, int e){
    LNode *p = GetLinkListNode(L,i-1);      //查找第i个节点的前驱元素
    if(p != NULL){      //查找成功
        LNode* new = (LNode *)malloc(sizeof(LNode));//创建的是结点,返回的是指向这个节点的指针
        if(!new){
            return 0;
        }  //内存空间分配失败
        new->data = e;  
        new->next = p->next;
        p->next = new;
        return 1;       //创建成功
    }
    
}//后插法插入节点，//前插法的插入操作和后插法一致，只需要将两者元素交换一下顺序即可

int DeleteLinkListNode(LinkList L,int i,int e){
    if(i<1){
        return NULL;
    }
    LNode * p = GetLinkListNode(L,i-1); //找到第i-1个节点，即被删除节点的前驱节点
    e = p->next->data;    //将被删除元素返还出去
    LNode * q = p->next;
    p->next = q->next;
    free(q);
    return 1;       //删除成功
}//删除位序为i的节点，并return出去

