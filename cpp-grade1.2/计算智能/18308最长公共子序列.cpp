#include <iostream>
#include "cstring"
using namespace std;
int main() {
    char a[1005],b[1005];
    cin>>a>>b;
    int aLen,bLen;
    aLen= strlen(a);bLen=strlen(b);
    int LCS[aLen+1][bLen+1];//+1是因为为了存放空集
    for(int i=0;i<aLen;i++)//初始化，第一行都是0
        LCS[0][i]=0;
    for(int i=0;i<bLen;i++)//初始化，第一列都是0
        LCS[i][0]=0;
    for(int i=1;i<bLen+1;i++){
        for(int j=1;j<aLen+1;j++){
            if(a[j]==b[i])
                LCS[i][j]=LCS[i-1][j-1]+1;
            else
                LCS[i][j]=max(LCS[i-1][j],LCS[i][j-1]);
        }
    }
    cout<<LCS[bLen][aLen]<<endl;
    return 0;
}
