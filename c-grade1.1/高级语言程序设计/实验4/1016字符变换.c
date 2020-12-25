#include<stdio.h>

int main(){
    char chars[5];
    int i;
    for(i=0;i<5;i++){
        scanf("%c",&chars[i]);
    }
    for(i=0;i<5;i++){
        if('A'<=chars[i]&&chars[i]<='Z'){
            chars[i]+=32;
        }
    }
    for(i=0;i<5;i++){
        printf("%c",chars[i]);
    }
}

//Description
//由键盘输入5个字符，将其中的大写字符变成小写（其它类型的字符不变），最后，按输入顺序输出这5个字符。
//
//
//
//输入样例
//ApPLe
//
//
//输出样例
//apple
//
