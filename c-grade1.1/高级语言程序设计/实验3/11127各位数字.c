#include<stdio.h>

int main(){
    int input;
    scanf("%d",&input);
    int output2 = input%10;
    input/=100;
    printf("%d\n",input%10);
    printf("%d\n",output2);

}


//Description
//�Ӽ�������һ��3λ������������Ҫ���Ⱥ���������İ�λ�������λ���֣���ռһ��
//
//
//
//�����ʽ
//һ����λ����
//
//
//�����ʽ
//��������İ�λ�������λ����
//
//
//��������
//123
//
//
//�������
//1
//3
