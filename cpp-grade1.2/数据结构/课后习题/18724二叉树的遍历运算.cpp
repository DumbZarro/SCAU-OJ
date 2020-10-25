#include <cstdio>//ASI
#include <cstring>
#include <iostream>
typedef long long ll;
using namespace std;
char x[1005],z[1005];
void dfs(int xl,int xr,int zl,int zr){
    if(xl>xr)
        return;
    char root=x[xl];
    int i,pos;
    for(i=zl;i<=zr;i++)
        if(z[i]==root)
        break;
    pos=i;
    int lchildlen=pos-zl;
    dfs(xl+1,xl+lchildlen,zl,pos-1);
    dfs(xl+lchildlen+1,xr,pos+1,zr);
    printf("%c",root);
}
int main()
{
//    freopen(".in","r",stdin);
//    freopen(".out","w",stdout);
    int i,j,n;
    scanf("%s",x+1);
    scanf("%s",z+1);
    n=strlen(x+1);
    dfs(1,n,1,n);
    return 0;
}
