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
//�ɼ�������5������������ж������ܷ�27�������ܵ������YES�������ܵ������NO����ע�⣬���ʱ��һ���жϽ��ռһ�У�5�������жϹ�ռ5�У���
//
//
//
//�����ʽ
//�ÿո�ָ�
//
//
//�����ʽ
//һ��һ���ж�
//
//
//��������
//8  27  17577  325  54
//
//
//�������
//NO
//YES
//YES
//NO
//YES
//
