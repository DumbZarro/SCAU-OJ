//https://www.nowcoder.com/test/16516564/summary

#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int n,nex[100005];
char a[100005];
int main()
{
    int i,j,len,p2,p3,p4;
    cin>>n;
    while(n--)
    {
        scanf("%s",a);
        len=strlen(a);
        for(i=0;i<len;i++)
            nex[i]=i+1;
        int p=0;
        while(p<len)
        {
            p2=nex[p];
            p3=nex[p2];
            p4=nex[p3];
            if(a[p]==a[p2])
            {
                if(a[p2]==a[p3]||a[p3]==a[p4])   /**< AAA   AABB*/
                {
                    nex[p2]=nex[p3];
                    continue;
                }
            }
            p=nex[p];
        }
        p=0;
        while(p<len)
        {
            printf("%c",a[p]);
            p=nex[p];
        }
        printf("\n");
    }

    return 0;
}
