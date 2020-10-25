#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int row[20],diagonal[2][30];//标记列和两条对角线的数组s
int cnt,n;
void dfs(int cur)
{
    if(cur==n+1) //到达递归边界
    {
        cnt++;
        return;
    }
    for(int i=1;i<=n;i++)
    {     //判断列上、两条对角线上是否已有棋子
        if(!row[i]&&!diagonal[0][cur+i]&&!diagonal[1][cur-i+n])
        {
            row[i]=diagonal[0][cur+i]=diagonal[1][cur-i+n]=1;
            dfs(cur+1);
            row[i]=diagonal[0][cur+i]=diagonal[1][cur-i+n]=0;
        }
    }
}
int main()
{
    //freopen("input.txt","r",stdin);
    memset(row,0,sizeof(row));
    memset(diagonal,0,sizeof(diagonal));
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        cnt=0;
        dfs(1);
        printf("%d\n",cnt);
    }
    return 0;
}
