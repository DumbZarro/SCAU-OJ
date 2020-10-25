/*
��������ֱ������ţ����ķ��������ǿ���ͨ��������ţ������ķ�����
��ͨ�����ܷ������Ȼ�����Եõ���ţ����ķ������ˡ�
��ô�������ţ������ķ������أ�����ţ��������һά�����ϣ�
Ȼ��ȷ����һͷ��ţ��m�֣��ڶ�ͷ��m-1�֣�����ͷ��m-1�֣�ֱ����nͷ��
��˲�����ķ�������m*(m-1)(n-1)�֣� ͬʱ�ܷ�������mn�֣�
��˷���ķ�����ans=(mn-m*(m-1)(n-1))%1000000007���˹��������������һ��ȡһ��ģ��
��ô�������ױ��ڴ档����������ݹ�ʽ��ans=(A%mod-B%mod+mod)%mod,
�����м���mod��Ϊ�˷�ֹ���ָ�������A%mod��B%mod������������ݵĹ�����ȡģ��
��������B%mod������ansʽ�����������m�������Ҫ�������ȡģ��
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

//ͬ�ඨ��
