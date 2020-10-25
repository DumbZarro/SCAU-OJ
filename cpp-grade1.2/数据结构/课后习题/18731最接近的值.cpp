#include<iostream>
#include<set>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    int n,i,x,v;
    multiset<int> s;//多重集合
    multiset<int>::iterator it;
    cin>>n;
    cin>>x;
    cout<<x<<' ';
    s.insert(x);
    for(i=2; i<=n; i++) {
        cin>>x;
        s.insert(x);
        it=s.lower_bound(x);//找出值x所在的位置
        if(it==s.begin()) { //最前
            it++;
            cout<<*it<<' ';
            continue;
        }
        it++;
        if(it==s.end()) { //最后
            it--;
            it--;
            cout<<*it<<' ';
            continue;
        }
        int last=*it;
        it--;//复位
        int cur=*it;
        it--;//往前调
        int pre=*it;
        if(cur-pre==last-cur) {
            cout<<last<<' ';
        } else if(cur-pre<last-cur) {
            cout<<pre<<' ';
        } else {
            cout<<last<<' ';
        }
    }
    return 0;
}

