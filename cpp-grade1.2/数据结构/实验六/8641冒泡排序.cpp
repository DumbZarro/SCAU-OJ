#include<iostream>
#include<algorithm>
using namespace std;
int d[200000];		    //定义一个足够大的数组
void Travers(int n)        //遍历函数
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
        int flag=0;             //定义一个flag做标记
        for(int j=0;j<n-1;j++)
        {
            if(d[j]>d[j+1])     //如果左边的值较小，冒泡
            {
                swap(d[j],d[j+1]);
                flag=1;         //有交换，标记
            }
        }
        Travers(n);             //每趟遍历
        if(!flag)               //如果没有交换，即无需再交换，结束程序
            return 0;
    }
    return 0;
}
