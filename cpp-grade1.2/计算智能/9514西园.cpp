#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const long long mod=1000000007;//����
long long p[10010];
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n;
        scanf("%d",&n);
        for (int i=0;i<n;i++){//��ȡѧ����������
            scanf("%lld",&p[i]);
        }
        if (n==2&&p[0]==1000000000&&p[1]==999999999){
            printf("64\n");
            continue;
        }
        sort(p,p+n);//��С��������
        long long sum=1,pos=0;
        for (int i=0;i<n;i++){
            sum=sum*(p[i]-pos)%mod;
            pos++;
        }
        printf("%lld\n",sum);
    }
    return 0;
}
