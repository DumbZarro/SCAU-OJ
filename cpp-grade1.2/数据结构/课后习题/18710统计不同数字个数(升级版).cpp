#include<iostream>
#include<cstdio>
using namespace std;

int n,c[200001];//不同数字0到200000,不能多不能少
int main(){
    int i,j=0;
    cin>>n;//输入数字个数
    int num[n];
    for(i=0;i<n;i++){
        scanf("%d",&num[i]);
    }
    for(i=0;i<n;i++){
        c[num[i]]++;
        if(c[num[i]]==1){
            j++;
        }
    }
    cout<<j;
    return 0;
}
