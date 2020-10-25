#include<iostream>
using namespace std;
int a[100005],n,q;
int search_best(int x) {
    int low=1,high=n,middle,best=n+1;
    while(low<=high) {
        middle=(low+high)/2;
        if(a[middle]>=x) {
            best=middle;//��¼�±�
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
    for(i=1; i<=n; i++) //��������
        cin>>a[i];
    cin>>q;
    for(i=1; i<=q; i++) { //q�β�ѯ
        cin>>x;
        cout<<search_best(x)<<endl;
    }
    return 0;
}
