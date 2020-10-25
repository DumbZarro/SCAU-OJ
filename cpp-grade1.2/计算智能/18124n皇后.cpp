#include <iostream>
#include <cmath>
using namespace std;
int N;
int res;
int queenPos[100];//下标是行,值是列
//用来存放算好的皇后位置。最左上角是(0,0)
void NQueen(int k){//前k-1行皇后已经摆好的情况下，摆第k行及其后的皇后
    if(k==N){//k是行,N是皇后数,若皇后都能摆则放置方法加一
        res++;
    }//
    for(int i=0;i<N;i++){//循环遍历列
        int j;
        for(j=0;j<k;j++){//循环遍历之前摆好的皇后
            if(queenPos[j]==i  ||  abs(queenPos[j]-i)==abs(k-j)){
            //if({摆好的第j个皇后的列==当前列}||{两个皇后之间的高==宽})
                break;
            }
        }
        if(j==k){//判断这一行是否能放
            queenPos[k]=i;//记录皇后的列数
            NQueen(k+1);//计算下一个皇后
        }
    }
}
int main(){
    int c;
    cin>>c;//读取case数
    while(c--){
        cin>>N;//读取皇后数
        res=0;
        NQueen(0);//从第0行开始摆皇后
        cout<<res<<endl;
    }
    return 0;
}
