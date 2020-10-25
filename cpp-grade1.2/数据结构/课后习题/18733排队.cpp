#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#include<vector>
#include<map>
#include<sstream>
using namespace std;
#define ll long long
int fa[300050];
int n,m;
int Find(int x) {
    return x==fa[x]?x:(fa[x]=Find(fa[x]));
}
void merger(int x,int y) {
    int xx=Find(x),yy=Find(y);
    fa[xx]=yy;
}
void init() {
    for(int i=1; i<=n; i++)
        fa[i]=i;
}
int main() {
    cin>>n>>m;
    init();
    for(int i=0; i<m; i++) {
        int x,y;
        cin>>x>>y;
        if(Find(x)==Find(y))
            continue;
        merger(x,y);
    }
    for(int i=1; i<=n-1; i++)
        cout<<Find(i)<<" ";
    cout<<Find(n);
    return 0;
}
