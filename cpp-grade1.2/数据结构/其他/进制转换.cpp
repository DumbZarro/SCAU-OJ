#include<iostream>
using namespace std;
void jin(int n,int m){
    if(n==0){
        return;
    }
    jin(n/m,m);
    if(n%m>=10){
        cout<<(char)(n%m-10+'A');
    }
    else{
        cout<<n%m;
    }
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int i,j,n,m;
    cin>>n>>m;
    if(n==0){
        cout<<0;
        return 0;
    }
    jin(n,m);
    return 0;
}
