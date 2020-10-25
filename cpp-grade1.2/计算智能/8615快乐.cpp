#include <iostream>
#include <cstdio>
int n,gethappy[51],losspow[51],power=2000,dp[51][2001];//n为输入的数据大小
using namespace std;
/*
这道题是0-1背包的改版,一开始没反应过来想用贪心,但是很明显不行
对于0-1背包问题，贪心选择之所以不能得到最优解是因为它无法保证最终能将背包装满,
部分闲置的背包空间使每公斤背包空间的价值降低了。事实上，在考虑0-1背包问题时，
应比较选择该物品和不选择该物品所导致的最终方案，然后再作出最好选择。
由此就导出许多互相重叠的子问题。这正是该问题可用动态规划算法求解的另一重要特征。
*/

int main(){
    int i,j;
    cin>>n;
    for(i=0;i<n;i++){//读取快乐
        cin>>gethappy[i];
    }
    for(i=0;i<n;i++){//读取精力
        cin>>losspow[i];
    }
    for(j=0;j<=power;j++){
        if(j>losspow[0]){
            dp[0][j]=gethappy[0];
        }
        else{
            dp[0][j]=0;
        }
    }
    for(i=1;i<n;i++){
        for(j=0;j<=power;j++){
            if(j>losspow[i]){//当还有精力的时候可以选择做或不做
                dp[i][j]=max(dp[i-1][j], dp[i-1][j-losspow[i]]+gethappy[i]);
                //dp[i-1][j-losspow[i]],对于前(i-1)个题，精力剩余为j-losspow[i-1]时的最大价值
                //当前结果=max({不写的结果},{写的结果})
                //写的结果=剩下精力可以写的最大快乐+当前物品的快乐
            }
            else{//写不了第i个题
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    printf("%d",dp[n-1][power]+1);//1为初始快乐值
    return 0;
}
