#include<iostream>
#include<set>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    int n,i,x,v;
    multiset<int> s;//���ؼ���
    multiset<int>::iterator it;
    cin>>n;
    cin>>x;
    cout<<x<<' ';
    s.insert(x);
    for(i=2; i<=n; i++) {
        cin>>x;
        s.insert(x);
        it=s.lower_bound(x);//�ҳ�ֵx���ڵ�λ��
        if(it==s.begin()) { //��ǰ
            it++;
            cout<<*it<<' ';
            continue;
        }
        it++;
        if(it==s.end()) { //���
            it--;
            it--;
            cout<<*it<<' ';
            continue;
        }
        int last=*it;
        it--;//��λ
        int cur=*it;
        it--;//��ǰ��
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

