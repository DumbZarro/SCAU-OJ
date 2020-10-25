#include<iostream>
#include<algorithm>
using namespace std;
int d[200000];//定义一个足够大的全局数组
void Travers(int n) {//遍历函数
    for(int i=0; i<n; i++)
        cout<<d[i]<<" ";
    cout<<endl;
}
int main() {
    int n;
    cin>>n;//n为待排个数
    for(int i=0; i<n; i++)
        cin>>d[i];
    for(int  i=0; i<n-1; i++) {//初始有序序列长度为1,总共需要遍历n-1次
        if(d[i]>d[i+1]) {//如果的右边的比较小
            int t=d[i+1],j;
            for(j=i+1; j>0; j--) {//将该位置之前的往右移动
                if(t<d[j-1])
                    d[j]=d[j-1];
                else//直到碰到比它小的数，将不再移动,跳出循环
                    break;
            }
            d[j]=t;//将它赋予当前位置,记得放外面(考虑t为最小的情况)
        }
        Travers(n);//每趟遍历
    }
    return 0;
}
