#include<iostream>
#include<cstdio>
using namespace std;

int n,c[200001];//��ͬ����0��200000,���ܶ಻����
int main(){
    int i,j=0;
    cin>>n;//�������ָ���
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
