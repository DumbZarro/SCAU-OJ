#include <iostream>
typedef long long ll;
using namespace std;
int ksm(int a,int n)
{
    if(n==1)
        return a;
    int  t=ksm(a,n/2); /**< a^(n/2) */
    t=t*t;
    if(n%2==1)
       t=t*a;
    return t;
}
int main()
{
    int i,j,a,n,m,x;
    cin>>a>>n;
    cout<<ksm(a,n);

    return 0;
}
//µÝ¹é,¶þ·Ö
