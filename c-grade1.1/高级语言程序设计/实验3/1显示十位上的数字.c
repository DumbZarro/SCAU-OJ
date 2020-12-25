#include<stdio.h>

int main(){
    int input;
    scanf("%d",&input);
    input /=10;
    printf("%d\n",input%10);
}

//描述
//由键盘输出一个3位整数（百位数字不为0），输出该数十位上的数字
//
//输入格式
//输入任意一个3位整数；
//输出格式
//输出该数十位上的数字
//输入样例
//158
//输出样例
//5
