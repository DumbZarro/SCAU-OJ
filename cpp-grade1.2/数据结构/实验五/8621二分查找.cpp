#include<iostream>
#include<cstdlib>
using namespace std;
typedef struct{
    int *nums;
    int length;
}seq;

int Creat_Seq(seq &s,int n){
    s.nums=(int*)malloc(n*sizeof(int));
    s.length=n;
    for(int i=0;i<n;i++){
        cin>>s.nums[i];
    }
}

int Search_Bin(seq &s,int key){
    int low=0,high=s.length-1,mid;
    while(low<=high){
        mid=(high+low)/2;
        if(s.nums[mid]==key){
            return mid;
        }
        else if(s.nums[mid]>key){
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return -1;
}

int main(){
    int n,key,pos;
    cin>>n;
    seq s;
    Creat_Seq(s,n);
    cin>>key;
    pos=Search_Bin(s,key);
    if(pos==-1){
        cout<<"The element is not exist.";
    }
    else{
        cout<<"The element position is "<<pos<<".";
    }
}


//#include<iostream>
//using namespace std;
//int Search_Bin(int* s,int n,int key){
//    int low,high,mid;
//    low=0;
//    high=n-1;
//    while(low<=high){
//        mid=(low+high)/2;
//        if(key<s[mid])
//            high=mid-1;
//        if(key>s[mid])
//            low=mid+1;
//        else
//            return mid;
//    }
//    return -1;
//}
//int main(){
//    int n,pos,key;
//    cin>>n;
//    int s[n+5];
//    for(int i=0;i<n;i++){
//        cin>>s[i];
//    }
//    cin>>key;
//    pos=Search_Bin(s,n,key);
//    if(pos==-1){
//        cout<<"The element is not exist.";
//    }
//    else{
//        cout<<"The element position is "<<pos<<".";
//    }
//}
