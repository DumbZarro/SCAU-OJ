#include <iostream>
#include <cstdio>
using namespace std;

int part(int date[],int low,int high,int n) {//完成一趟快排,返回枢轴位置
    date[0]=date[low];//将low位置的值放到哨兵
    int mid=date[low];
    while(low<high) {
        while(low<high&&date[high]>=mid)//如果当前high的值比mid大，则自减，直到找到比mid小的值的位置
            --high;
        date[low]=date[high];//将该位置的值赋予low位置
        while(low<high&&date[low]<=mid)//如果当前low的值比mid小，则自减，直到找到比mid大的值的位置
            low++;
        date[high]=date[low];//将该位置的值赋予high位置
    }
    date[low]=date[0];//将哨兵的值赋予low位置
    for(int i=1; i<=n; i++)
        printf("%d ",date[i]);
    cout<<endl;
    return low;//返回low，此时的low已经变化了，其作为中间位置
}/*此函数中，low与high的值都是有可能在变化的*/

void quick_sort(int date[],int low,int high,int n) {
    if(low<high) {
        int pivotloc=part(date,low,high,n);//
        quick_sort(date,low,pivotloc-1,n);//递归将枢轴左边的排序
        quick_sort(date,pivotloc+1,high,n);//递归将枢轴右边的排序
    }
}

int main() {
    int n;
    cin>>n;
    int date[n+5];//按需求定义一个稍大的数组
    for(int i=1; i<=n; i++)
        cin>>date[i];//录入数据
    quick_sort(date,1,n,n);//调用sort函数
    return 0;
}
