#include<stdio.h>

int main(){
    int input[5];
    char yes[]="YES";
    char no[]="NO";
    int i;
    for(i=0;i<5;i++){
        scanf("%d",&input[i]);
    }
    for(i=0;i<5;i++){
        if((input[i]%27)==0){
            printf("%s\n",yes);
        }else{
            printf("%s\n",no);
        }
    }
}

//Description
//由键盘输入5个整数，逐个判断它们能否被27整除，能的输出“YES”，不能的输出“NO”（注意，输出时，一个判断结果占一行，5个数的判断共占5行）。
//
//
//
//输入格式
//用空格分隔
//
//
//输出格式
//一行一个判断
//
//
//输入样例
//8  27  17577  325  54
//
//
//输出样例
//NO
//YES
//YES
//NO
//YES
//
