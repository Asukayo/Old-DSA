#include <stdlib.h>
#include <stdio.h>

typedef struct  LNode{
    int data;//数据域
    struct LNode* next;//指针域
}LNode,*LinkList;

void Reverse(int *nums){
    LinkList L  = (LNode *)malloc(sizeof(LNode));   //初始化链表操作
    LNode *s;
    L->next = NULL;
    int i = 0;
    for(i;i<5;i++){
        s = (LNode *)malloc(sizeof(LNode));
        s->data = nums[i];
        s->next = L->next;
        L->next = s;
    }
    LNode *a= L->next;
    int b = 0;
    while(a!=NULL && b<5){
        printf("%d,",a->data);
        a = a->next;
        b++;
    }
}

int main(){
    int nums[5] = {1,2,3,4,5};
    Reverse(nums);
    return 1;
}