#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN =1010;
int a[MAXN];//父序列
int maxLen[MAXN];//存放以i为终点的最长上升子序列长度

int main(){
    int N;
    cin >> N;//读取序列长
    for( int i = 1;i <= N;++i){//读取父序列且初始化子序列
         cin >> a[i];
         maxLen[i] = 1;
    }
    for( int i = 2; i <= N; ++i){
         for( int j = 1; j < i; ++j){//每次求以第i个数为终点的最长上升子序列的长度
            //逐个子序列长度对比
            if(a[i]>a[j]){//j<i
                maxLen[i] = max(maxLen[i],maxLen[j]+1);
            }
         }
    }
    cout<< * max_element(maxLen+1,maxLen + N + 1 );//返回数组最大值(first,end),记得加*
    return 0;
}//n**2
