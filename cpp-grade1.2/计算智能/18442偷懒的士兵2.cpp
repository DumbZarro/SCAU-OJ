#include <iostream>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
int big = 2000000000;
long long f(int i,int a,int step){
    if(i<3){
        return a;
    }
    if(i==3){
        return big;
    }
    else{
        int leftmin =f(i/2,a+step,step*2);
        int rightmin =f((i+1)/2,a,step*2);
        return(leftmin<rightmin?leftmin:rightmin);
    }
}

int main(){
    int n;
    while(1){
        scanf("%d",&n);
        if(n==0) break;
        long long ret = f(n, 1, 1);
        if(ret!=big)
            printf("%lld\n", ret);
        else
            printf("0\n");
    }
}

