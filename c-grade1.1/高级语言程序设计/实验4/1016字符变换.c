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
//�ɼ�������5���ַ��������еĴ�д�ַ����Сд���������͵��ַ����䣩����󣬰�����˳�������5���ַ���
//
//
//
//��������
//ApPLe
//
//
//�������
//apple
//
