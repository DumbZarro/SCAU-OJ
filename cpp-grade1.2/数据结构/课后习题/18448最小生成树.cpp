#include<algorithm>
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<queue>
using namespace std;
#define ll long long
#define maxx 0x3f3f3f3f
ll read() {
    ll ans=0,sign=1;
    char ch;
    ch=getchar();
    while(ch<'0'||ch>'9') {
        if(ch=='-')
            sign=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9') {
        ans=(ans<<1)+(ans<<3)+(ch^48);
        ch=getchar();
    }
    return sign*ans;
}
typedef struct {
    ll x,y,w;
} NODE;
NODE graph[2005];
int fa[2005];
ll ans=0;
int Find(int x) {
    return x==fa[x]?x:(fa[x]=Find(fa[x]));
}
int n,m;
bool cmp(NODE a,NODE b) {
    return a.w<b.w;
}
void Kruskal() {
    for(int i=1; i<=m; i++) {
        int x=Find(graph[i].x);
        int y=Find(graph[i].y);
        if(x!=y) {
            fa[x]=y;
            ans+=graph[i].w;
        }
    }
}
int main() {
    n=read();
    m=read();
    for(int i=1; i<=m; i++) {
        graph[i].x=read();
        graph[i].y=read();
        graph[i].w=read();
    }
    sort(graph+1,graph+1+m,cmp);
    for(int i=1; i<=n; i++)
        fa[i]=i;
    Kruskal();
    cout<<ans<<'\n';
    return 0;
}
//¿ËÂ³Ë¹¿¨¶û
