#include<stdio.h>

int main(){
    int a,b,c;
    scanf("%d,%d,%d",&a,&b,&c);
    if(a<b){
        if(b<c){
            printf("%d,%d,%d",a,b,c);
        }else if(c<a){
            printf("%d,%d,%d",c,a,b);
        }else{
            printf("%d,%d,%d",a,c,b);
        }
    }else{
        if(a<c){
            printf("%d,%d,%d",b,a,c);
        }else if(c<b){
            printf("%d,%d,%d",c,b,a);
        }else{
            printf("%d,%d,%d",b,c,a);
        }
    }
}

//Description
//由键盘输入三个整数a、b、c，按从小到大的顺序输出这三个数。
//
//
//
//输入格式
//三个数由逗句分隔
//
//
//输入样例
//65,45,90
//
//
//输出样例
//45,65,90
