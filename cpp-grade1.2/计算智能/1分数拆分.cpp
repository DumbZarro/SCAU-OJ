#include <iostream>
#include <cstdio>
using namespace std;
void solve(long long k)
{
    long long x1,x2;//设x1<x2<x3,避免重复
    for(x1=k+1; x1<=3*k; x1++){//x1大于k小于3k,放缩
        if(x1*k%(x1-k)==0 && x1*k/(x1-k)>=x1){//两项的情况,或者三项情况的第一项
            printf("1/%lld=1/%lld+1/%lld\n", k, x1*k/(x1-k), x1);
        }
        double k1=(double)x1*k/(x1-k)+1;//后两项之和
        for(x2=k1; x2<=2*k1 ; x2++){//三项的情况的后两项
            //你要填写的部分在这里
            if(x2<x1){
                continue;
            }
//            if(x2*k1%(x2-k1)==0 && x2*k1/(x2-k1)>=x2){//两项的情况,或者三项情况的第一项
//                printf("1/%lld=1/%lld+1/%lld+/%lld\n", k, x2*k1/(x2-k1), x2, x1);
//            }
            if(k*x1*x2%((x1-k)*x2-k*x1)==0 && k*x1*x2/((x1-k)*x2-k*x1)>=x2){//两项的情况,或者三项情况的第一项
                printf("1/%lld=1/%lld+1/%lld+1/%lld\n", k, k*x1*x2/((x1-k)*x2-k*x1), x2, x1);
            }
        }
    }
    cout<<endl;
}

int main(){
    long long k;
    while(cin>>k, k!=0){
        solve(k);
    }
    return 0;
}
