#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int a[1000005];
int main()
{
    ios::sync_with_stdio(0),cin.tie(0);
    int i,j,n,m,x;
    multiset<int> s;/**< set存位置 */
    cin>>n;
    for(i=1; i<=n; i++)
        cin>>a[i];
    for(i=1;i<=n;i++) /**< b的全部放到s里面去 */
        cin>>x,s.insert(x);
    for(i=1; i<=n; i++)
    {   /**< 对ai来说，>=n-a[i] */
        multiset<int>::iterator it=s.lower_bound(n-a[i]);
        if(it==s.end())
            it=s.begin();
        cout<<(a[i]+*it)%n<<' ';
        s.erase(it);
    }
    return 0;
}
