/*
由于难于直接求奶牛发疯的方案，我们可以通过先求奶牛不发疯的方案，
再通过与总方案做差，然后便可以得到奶牛发疯的方案数了。
那么如何求奶牛不发疯的方案数呢？把奶牛们想象在一维数轴上，
然后确定第一头奶牛有m种，第二头有m-1种，第三头有m-1种，直至第n头，
因此不发疯的方案数有m*(m-1)(n-1)种， 同时总方案数有mn种，
因此发疯的方案数ans=(mn-m*(m-1)(n-1))%1000000007。此过程中如果不是算一步取一次模，
那么极其容易爆内存。因此我们依据公式：ans=(A%mod-B%mod+mod)%mod,
括号中加上mod是为了防止出现负数，而A%mod和B%mod可以在求快速幂的过程中取模，
但是由于B%mod；又在ans式子里面乘上了m，因此又要对其进行取模。
*/

#include <iostream>
typedef long long ll;
using namespace std;
const ll mod=1000000007;
long long kpow(int m,int n)
{
    if(n==0)
        return 1;
    ll temp=kpow(m,n/2);
    ll ans=temp*temp%mod;
    if(n%2==1)
        ans=ans*m%mod;
    return ans;
}
int main()
{
    ios::sync_with_stdio(0),cin.tie(0);
    ll n,m;
    cin>>n>>m;
    n=n%mod;
    m=m%mod;
    cout<<(kpow(m,n)-m*kpow(m-1,n-1)%mod +mod )%mod;
    return 0;
}

//同余定理
