#include<iostream>
using namespace std;
int a[100005],n,q;
int search_best(int x) {
    int low=1,high=n,middle,best=n+1;
    while(low<=high) {
        middle=(low+high)/2;
        if(a[middle]>=x) {
            best=middle;//记录下标
            high=middle-1;
        }
        else
            low=middle+1;
    }
    return best;
}
int main() {
    ios::sync_with_stdio(false);
    int i,x;
    cin>>n;
    for(i=1; i<=n; i++) //输入序列
        cin>>a[i];
    cin>>q;
    for(i=1; i<=q; i++) { //q次查询
        cin>>x;
        cout<<search_best(x)<<endl;
    }
    return 0;
}
