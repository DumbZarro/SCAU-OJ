#include <iostream>
#include <math.h>
#include <stdlib.h>
using namespace std;

int main()
{
    int k,i,n,flag;
    cin>>n;//输入数据的组数
    while(n--){
        flag=0;
        cin>>k;//输入一遍
        for(i=(k*k+1)/2;i>sqrt(k*k/2);i--)
        {
            if(i!=k&&(int)sqrt(abs(i*i-k*k))*(int)sqrt(abs(i*i-k*k))==abs(i*i-k*k))
            {
                flag=1;//标记有解
                cout<<i<<","<<sqrt(abs(i*i-k*k))<<endl;
            }
        }

        if(flag==0)//无解
        {
            cout<<endl;
        }
        if(n!=0)//两组之间空一行
        {
            cout<<endl;
        }
    }
}
