#include <iostream>
#include <cstdio>
using namespace std;
void solve(long long k)
{
    long long x1,x2;//��x1<x2<x3,�����ظ�
    for(x1=k+1; x1<=3*k; x1++){//x1����kС��3k,����
        if(x1*k%(x1-k)==0 && x1*k/(x1-k)>=x1){//��������,������������ĵ�һ��
            printf("1/%lld=1/%lld+1/%lld\n", k, x1*k/(x1-k), x1);
        }
        double k1=(double)x1*k/(x1-k)+1;//������֮��
        for(x2=k1; x2<=2*k1 ; x2++){//���������ĺ�����
            //��Ҫ��д�Ĳ���������
            if(x2<x1){
                continue;
            }
//            if(x2*k1%(x2-k1)==0 && x2*k1/(x2-k1)>=x2){//��������,������������ĵ�һ��
//                printf("1/%lld=1/%lld+1/%lld+/%lld\n", k, x2*k1/(x2-k1), x2, x1);
//            }
            if(k*x1*x2%((x1-k)*x2-k*x1)==0 && k*x1*x2/((x1-k)*x2-k*x1)>=x2){//��������,������������ĵ�һ��
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
