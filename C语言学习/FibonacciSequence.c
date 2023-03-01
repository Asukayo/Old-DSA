//斐波那契数列的顺序求解和递归求解
#include <stdio.h>

int SeqSolution(int i){
    if(i == 0){
        return 0; 
    }else if(i == 1){
        return 1;
    }else{
        int a = 0,b = 1,k=0;
        for(k = 1;k<=i/2;k++){
            a = a+b;
            b = a+b;
        }
        if(k%2==0){
            return a;
        }else{
            return b;
        }
    }
}//参数i是要求解的第i个元素

int recursionSolution(int i ){
    //递归算法 1、递归边界 2、递归条件
    if(i == 0){
        return 0;
    }else if(i== 1){
        return 1;
    }else{
        return recursionSolution(i-1)+recursionSolution(i-2);
    }
}

int main(){
    int i = 5;
    int a = recursionSolution(6);
    printf("%d",a);
    return 1;
}