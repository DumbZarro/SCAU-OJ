#include<iostream>
#include<cstdio>
using namespace std;
void hnt(int n,char A,char B,char C){//A�ϵ�N�����ӽ���B�ƶ���C
    if(n==1){
        printf("������%d��%c,�ƶ���%c\n",n,A,C);
        return;
    }
    hnt(n-1,A,C,B);//��������������һ���Ǵ�A�ƶ���B��
    printf("������%d��%c�ƶ���%c\n",n,A,C);//�����ڶ�������һ���Ǵ�A�Ƶ�C��
    hnt(n-1,B,A,C);//�����С��һ������һ���Ǵ�B�ƶ���C��
}

int main(){
    int i,j,n;
    cin>>n;
    hnt(n,'A','B','C');
    return 0;
}
