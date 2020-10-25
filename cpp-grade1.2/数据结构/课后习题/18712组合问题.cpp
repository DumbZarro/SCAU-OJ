#include<iostream>
using namespace std;
int n,k,ans[100];
void print(){
    for(int i=1;i<=k;i++){
        cout<<ans[i]<<' ';
    }
    cout<<endl;
}

void dfs(int x,int cur){
    if(cur==k+1){
        print();
        return;
    }
    int i;
    for(i=x;i>=1;i--){
        ans[cur]=i;
        dfs(i-1,cur+1);
    }
}


int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int i,j,l,p;
    cin>>n>>k;
    dfs(n,1);
    return 0;

}
