#include<iostream>
#include<algorithm>
using namespace std;
int d[100000000];//�洢�Ѿ������n
int F(int n){
    if(!(n&(n-1)))//0��2��n���ݷ���0
        return 0;
    if(n<100000000&&d[n]>0)//�����ʱ��n�Ѿ���������������У���ֱ�ӷ���
        return d[n];
    else if(n==3)//��nΪ3ʱΪһ�ַ���������1
        return 1;
    else{
        int t=F((n+1)/2)+F(n/2);//�ݹ��ʱ������λ�ú�ż��λ��,c���Եĳ���ȡ������������С��
        if(n<100000000)//��n�����鷶Χ��ʱ���ɴ�������
            d[n]=t;
        return t;//���صݹ麯����Ľ��
    }
}
int main(){
    int n;
    while(cin>>n&&n){//������nΪ0ʱ�˳�{
        cout<<F(n)<<endl;//���õݹ麯������Ϊ������������ֵ������ֱ���������
    }
    return 0;
}
