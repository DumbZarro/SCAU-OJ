#include<iostream>
#include<algorithm>
using namespace std;
int d[100000000];//存储已经算过的n
int F(int n){
    if(!(n&(n-1)))//0和2的n次幂返回0
        return 0;
    if(n<100000000&&d[n]>0)//如果此时的n已经算过并存入数组中，可直接返回
        return d[n];
    else if(n==3)//当n为3时为一种方案，返回1
        return 1;
    else{
        int t=F((n+1)/2)+F(n/2);//递归此时的奇数位置和偶数位置,c语言的除法取整方案是舍弃小数
        if(n<100000000)//当n在数组范围内时，可存入数组
            d[n]=t;
        return t;//返回递归函数里的结果
    }
}
int main(){
    int n;
    while(cin>>n&&n){//当输入n为0时退出{
        cout<<F(n)<<endl;//调用递归函数，因为函数本身返回数值，所以直接输出即可
    }
    return 0;
}
