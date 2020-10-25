#include<algorithm>
#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<queue>
#include<stack>
using namespace std;
#define ll long long
#define maxn 0x3f3f3f3f
int n,m;
int graph[105][105];
int dist[105];
bool vis[105];
void init() {
    memset(graph,maxn,sizeof(graph));
    memset(dist,maxn,sizeof(dist));
    for(int i=1; i<=103; i++)
        graph[i][i]=0;
}
void dijkstra() {
    for(int i=1; i<=n; i++)
        dist[i]=graph[1][i];
    for(int i=1; i<=n; i++) {
        int cur=-1,minx=maxn;
        for(int j=1; j<=n; j++) {
            if(!vis[j]&&dist[j]<minx) {
                minx=dist[j];
                cur=j;
            }
        }
        if(cur==-1) {
            break;
        }
        vis[cur]=1;
        for(int j=1; j<=n; j++) {
            if(!vis[j]&&graph[cur][j]!=maxn&&dist[j]>dist[cur]+graph[cur][j])
                dist[j]=dist[cur]+graph[cur][j];
        }
    }
}
int main() {
    cin>>n>>m;
    init();
    for(int i=0; i<m; i++) {
        int x,y,z;
        cin>>x>>y>>z;
        if(graph[x][y]>z)
            graph[x][y]=graph[y][x]=z;
    }
    dijkstra();
    if(dist[n]!=maxn)
        cout<<dist[n]<<'\n';
    else
        cout<<-1<<'\n';
    return 0;
}
