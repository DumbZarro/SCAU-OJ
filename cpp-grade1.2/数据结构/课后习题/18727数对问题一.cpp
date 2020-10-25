#include<iostream>
#include<string>
#include<algorithm>
#include<cstdio>
using namespace std;
#define ll long long
int main()
{
    int n,c;
    int a[10005];
    cin>>n>>c;
    for(int i=0; i<n; i++)
        cin>>a[i];
    sort(a,a+n);
    int ans=0;
    for(int i=0; i<n-1; i++)
        for( int j=i+1; j<n; j++)
        {
            if(abs(a[j]-a[i])==c)
                ans++;
            else if(abs(a[j]-a[i])>c)
                break;
        }
    cout<<ans<<endl;
    return 0;
}
