//---------------顺序存储的特点----------------

//1、随机访问，在O(1)的时间内可以找到需要的元素
//2、存储密度高，节点只存储元素
//3、插入删除操作需要移动大量元素
//4、拓展容量不方便

#include <stdlib.h>//要使用malloc 和free函数

#define InitSize 10//默认的最大长度
//------静态分配------
typedef struct SqList
{
    int datas[InitSize];    //顺序表的元素
    int length;             //顺序表的当前长度
}SqList;

//------动态分配------
typedef struct SeqList
{
    int *data ; //指示动态分配的数组的指针
    int MaxSize,length; //数组的最大容量和当前长度
}SeqList;

void InitList(SeqList *L){
    //用malloc函数申请一片连续的存储空间
    L->data = (int *)malloc(sizeof(int)*InitSize);
    L->length = 0;
    L->MaxSize = InitSize;
}//创建动态分配的顺序表



