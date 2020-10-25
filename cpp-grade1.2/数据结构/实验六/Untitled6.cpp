#include<iostream>
#include<algorithm>
using namespace std;
int d[20000];
void traverse(int n){
    for(int i=0;i<n;i++){
        cout<<d[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>d[i];
    }
    for(int i=0;i<n-1;i++){
        if(d[i]<d[i+1]){
            int t=d[i+1];
            for(int j=i+1;j>0;j--){
                if(t<d[j-1]){
                    d[j]=d[j-1];
                }
                else
                    break;
            }
            d[j]=t;
        }
        traverse(n);
    }
    return 0;
}
