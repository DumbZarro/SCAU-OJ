#include<iostream>
#include<algorithm>
using namespace std;
int d[100000000];//�洢�Ѿ������n
int F(int n)
{
    if(n<100000000&&d[n]>0)//�����ʱ��n�Ѿ���������������У���ֱ�ӷ���
        return d[n];
    if(n==3)
        return 1;
    else if(n<3)//����3�Ĳ���������
        return 0;
    else
    {
        int t=F((n+1)/2)+F(n/2);//�ݹ��ʱ������λ�ú�ż��λ��
        if(n<100000000)//��n�����鷶Χ��ʱ���ɴ�������
            d[n]=t;
        return t;//���صݹ麯����Ľ��
    }
}
int main()
{
    int n;
    while(cin>>n&&n)//������nΪ0ʱ�˳�
    {
        cout<<n-3*F(n)<<endl;//���õݹ麯������Ϊ���������ص���ȥѲ��ʿ���ķ�������n��ȥ3��������Ϊ��ȥѲ�ߵ�
    }
    return 0;
}

