#include<iostream>
using namespace std;
int n,a[100005],temp[100005];


void mergeSort(int a[],int left,int right,int temp[]) {
    if(right-left>1){
        int mid = left+(right-left)/2;
        int temp_left=left,temp_right=mid,i=left;
        mergeSort(a,left,mid,temp);
        mergeSort(a,mid,right,temp);
        while(temp_left<mid || temp_right<right) {
            if(temp_right>=right||(temp_left<mid&&a[temp_left]<=a[temp_right])) {
                temp[i++]=a[temp_left++];
            } else {
                temp[i++]=a[temp_right++];
            }
        }
        for(i=left; i<right; i++) {
            a[i]=temp[i];
        }
    }
}

int main() {
    ios::sync_with_stdio(0),cin.tie(0);
    int i;
    cin>>n;
    for(i=0; i<n; i++) {
        cin>>a[i];
    }
    mergeSort(a,0,n,temp);
    for(i=0; i<n; i++) {
        cout<<a[i]<<" ";
    }
    cout<<endl<<sum;
    return 0;
}
