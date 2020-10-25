#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
int map1[105][105];
int dist[105][105];
int n,m;
void floyd() {
    int i,j,k;
    for(k=1; k<=n; k++)
        for(i=1; i<=n; i++)
            for(j=1; j<=n; j++)
                if(map1[i][j]>map1[i][k]+map1[k][j])
                    map1[i][j]=map1[i][k]+map1[k][j];
}
int main() {
    cin>>n>>m;
    memset(map1,0x3f3f3f3f,sizeof(map1));
    for(int i=0; i<105; i++)
        map1[i][i]=0;
    for(int i=1; i<=m; i++) {
        int x,y,z;
        cin>>x>>y>>z;
        map1[x][y]=-z;
    }
    floyd();
    cout<<-map1[1][n]<<'\n';
    return 0;
}
