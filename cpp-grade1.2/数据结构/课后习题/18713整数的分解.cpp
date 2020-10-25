#include <iostream>
using namespace std;
int n,ans[100],c=0;
void print(int k)
{
    cout<<n<<'=';
    for(int i=1; i<=k; i++)
    {
        if(i!=1)
            cout<<'+';
        cout<<ans[i];
    }
    cout<<endl;
}
void dfs(int pre,int rest,int cur)/**< 我怎么知道前一个是谁？*/
{
    int i;
    for(i=min(pre,rest); i>=1; i--)
    {
        ans[cur]=i;
        if(rest-i==0)
            print(cur),c++;
        else
            dfs(i,rest-i,cur+1);
    }
}
int main()
{
    ios::sync_with_stdio(0),cin.tie(0);
    int i,j,l,p;
    cin>>n;
    dfs(n,n,1);
    return 0;
}
