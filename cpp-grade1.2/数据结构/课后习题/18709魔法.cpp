#include<iostream>
using namespace std;
int a[200005];
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int i,n,time,one=0,two=0,minv=0;
    cin>>n;
    for(i=1;i<=n;i++){//输入并计算后半段2的值
        cin>>a[i];
        two += a[i];
    }
    minv=2*n-two;
    for(i=1;i<=n;i++){
        one += a[i];
        two -= a[i];
        time = 2*n+one-3*i-two;//(one-i)+(2*(n-i)-two)
        minv=time<minv?time:minv;
    }
    cout<<minv;
}
