#include <stdio.h>

// 冒泡排序本质上就是两个数进行交换的过程
// 总共将进行n-1次

//void SwapTwoNumsByComparation
void SwapTwoNumsByComparation(int *a,int *b){
    int temp = 0;
    if((*a)>(*b)){
        temp = *a;
        *a = *b;
        *b = temp;
    }
}

// void MPSort
// int *a int型数组
// length 是数组的长度
void MPSort(int *a,int length){
    int i,j,k;
    for(i = 0;i<length-1;i++){  //length = 5 所以要执行4次
        for(j = 1;j<length-i;j++){
            SwapTwoNumsByComparation(a+j-1,a+j);
        }
    }
    for(k = 0;k<length;k++){
        printf("%d,",*(a+k));
    }
} 

int main(){
    int nums[5] = {3,5,2,1,4};
    MPSort(nums,5);
    return 0;
}
