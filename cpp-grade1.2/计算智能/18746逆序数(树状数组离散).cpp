#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
using namespace std;
const int MAXN=500010;
int c[MAXN];
int b[MAXN];
int n;
struct Node
{
    int index;//序号
    int v;
}node[MAXN];
bool cmp(Node a,Node b)
{
    return a.v<b.v;
}
int lowbit(int x)
{
    return x&(-x);
}
void add(int i,int val)
{
    while(i<=n)
    {
        c[i]+=val;
        i+=lowbit(i);
    }
}
int sum(int i)
{
    int s=0;
    while(i>0)
    {
        s+=c[i];
        i-=lowbit(i);
    }
    return s;
}
int main()
{
   // freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    while(scanf("%d",&n),n)
    {
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&node[i].v);
            node[i].index=i;
        }
        memset(b,0,sizeof(b));
        memset(c,0,sizeof(c));
        //离散化
        sort(node+1,node+n+1,cmp);
        //将最小的编号为1
        b[node[1].index]=1;
        for(int i=2;i<=n;i++)
        {
            if(node[i].v!=node[i-1].v) b[node[i].index]=i;
            else b[node[i].index]=b[node[i-1].index];
        }
        long long  ans=0;
        //这里用的很好
        //一开始c数组都是0，然后逐渐在b[i]处加上1；
        for(int i=1;i<=n;i++)
        {
            add(b[i],1);
            ans+=sum(n)-sum(b[i]);
        }
        printf("%I64d\n",ans);
    }
    return 0;
}
