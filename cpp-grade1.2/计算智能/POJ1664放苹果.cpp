#include<iostream>
#include<iomanip>
#include<math.h>
#include<string>
#include<cstring>
using namespace std;
int f(int m,int n){
    if(n==1){//盘子只有一个
        return 1;
    }
    if(m<=1){//苹果只剩一个或更少
        return 1;
    }
    if(m-n>=0){//苹果多于盘子
        return f(m,n-1)+f(m-n,n);//空n个盘子的若干种放法+不空盘子的方法
        //每个盘子放一个和每个盘子都空着是一样的
    }
    else{//苹果少于盘子
        return f(m,n-1);//空n个盘子的若干种放法 -1即空一个盘子
    }
}

int main(){
    int x,i,m,n;//m个苹果,n个盘子
    cin>>x;//读取组数
    for(i=1;i<=x;i++){
        cin>>m>>n;
        cout<<f(m,n)<<endl;
    }
    return 0;
}
