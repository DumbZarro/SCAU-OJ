#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
using namespace std;
vector<int> v[30];
int a[30],c[30];
int main() {
    int n,m,cnt=0;
    cin>>n>>m;
    for(int i=1; i<=m; i++) {
        int x,y;
        cin>>x>>y;
        v[x].push_back(y);
        a[y]++;
    }
    priority_queue<int,vector<int>,greater<int> >q;
    for(int i=1; i<=n; i++) {
        if(!a[i])
            q.push(i);
    }
    while(!q.empty()) {
        int x=q.top();
        q.pop();
        for(int i=0; i<v[x].size(); i++) {
            a[v[x][i]]--;
            if(!a[v[x][i]])
                q.push(v[x][i]);
        }
        c[++cnt]=x;
    }
    for(int i=1; i<=cnt; i++)
        cout<<c[i]<<" ";
    return 0;
}

