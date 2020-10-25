#include<iostream>
typedef long long ll;
using namespace std;
char a[15][15];
int n,m,v[15][15]={0},ok=0;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,1};
void dfs(int x,int y)
{
    if(x==n&&y==m)
    {
        ok=1;
        return;
    }
    v[x][y]=1;
    for(int i=0;i<4&&ok==0;i++)/**< x=1,y=1 :(2,1),(1,2),(0,1)(1,0)*/
    {
        int cx=x+dx[i],cy=y+dy[i];
        if(cx>=1&&cx<=n&&cy>=1&&cy<=m&&v[cx][cy]==0&&a[cx][cy]=='0')
            dfs(cx,cy);
    }
}
int main()
{
    ios::sync_with_stdio(0),cin.tie(0);
    int i,j;
    cin>>n>>m;
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
        cin>>a[i][j];
    dfs(1,1);
    if(ok)
        cout<<"yes";
    else
        cout<<"no";
    return 0;
}
