#include<iostream>
#include<algorithm>
using namespace std;
int d[200000];		    //����һ���㹻�������
void Travers(int n)        //��������
{
    for(int i=0;i<n;i++)
        cout<<d[i]<<" ";
    cout<<endl;
}
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>d[i];
    for(int i=0;i<n;i++)
    {
        int flag=0;             //����һ��flag�����
        for(int j=0;j<n-1;j++)
        {
            if(d[j]>d[j+1])     //�����ߵ�ֵ��С��ð��
            {
                swap(d[j],d[j+1]);
                flag=1;         //�н��������
            }
        }
        Travers(n);             //ÿ�˱���
        if(!flag)               //���û�н������������ٽ�������������
            return 0;
    }
    return 0;
}
