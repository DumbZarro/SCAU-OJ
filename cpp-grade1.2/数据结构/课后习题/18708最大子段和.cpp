#include <iostream>
typedef long long ll;
using namespace std;
int n,a,s[200005],mins[200005];/**< 前缀和存储第1个到第i个这一段的和 */
int main()
{
    ios::sync_with_stdio(0),cin.tie(0);
    int i,j,k,maxsum=-99999999;//int 2e9
    cin>>n;
    for(i=1; i<=n; i++)
    {
        cin>>a;
        s[i]=s[i-1]+a;
        mins[i]=min(mins[i-1],s[i]);
        maxsum=max(maxsum,s[i]-mins[i-1]);
    }
    cout<<maxsum;
    return 0;
}
