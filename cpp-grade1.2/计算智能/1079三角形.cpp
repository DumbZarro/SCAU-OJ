#include <iostream>
#include <math.h>
#include <stdlib.h>
using namespace std;

int main()
{
    int k,i,n,flag;
    cin>>n;//�������ݵ�����
    while(n--){
        flag=0;
        cin>>k;//����һ��
        for(i=(k*k+1)/2;i>sqrt(k*k/2);i--)
        {
            if(i!=k&&(int)sqrt(abs(i*i-k*k))*(int)sqrt(abs(i*i-k*k))==abs(i*i-k*k))
            {
                flag=1;//����н�
                cout<<i<<","<<sqrt(abs(i*i-k*k))<<endl;
            }
        }

        if(flag==0)//�޽�
        {
            cout<<endl;
        }
        if(n!=0)//����֮���һ��
        {
            cout<<endl;
        }
    }
}
