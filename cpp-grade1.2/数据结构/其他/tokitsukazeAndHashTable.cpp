#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int a[1000005];
int main()
{
    ios::sync_with_stdio(0),cin.tie(0);
    int i,j,n,m,x;
    multiset<int> s;/**< set��λ�� */
    cin>>n;
    for(i=1; i<=n; i++)
        cin>>a[i];
    for(i=1;i<=n;i++) /**< b��ȫ���ŵ�s����ȥ */
        cin>>x,s.insert(x);
    for(i=1; i<=n; i++)
    {   /**< ��ai��˵��>=n-a[i] */
        multiset<int>::iterator it=s.lower_bound(n-a[i]);
        if(it==s.end())
            it=s.begin();
        cout<<(a[i]+*it)%n<<' ';
        s.erase(it);
    }
    return 0;
}
