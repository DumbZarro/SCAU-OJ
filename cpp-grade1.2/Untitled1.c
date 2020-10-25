#include<cstdio>
#include<cstdlib>
using namespace std;
typedef long long ll;
int sum=0;

ll f(int i){
    sum++;
    if(i<3){
        return 0;
    }
    if(i==3){
        return 1;
    }
    return f(i/2)+f((i+1)/2);
}


int main(){
    int n;
    while(1){
        scanf("%d",&n);
        if(n==0){
            break;
        }
        printf("%lld\n",f(n));
    }
    printf("%d\n",sum);
}
