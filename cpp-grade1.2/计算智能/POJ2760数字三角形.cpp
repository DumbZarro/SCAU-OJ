#include<iostream>
#include<algorithm>
using namespace std;
int a[120][120];//状态
int maxsum[120];//条件数组
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){//读入数字三角形
        for(int j=1;j<=i;j++){
            cin>>a[i][j];
        }
	}
	for(int i=n,j=1;j<=n;j++){//最后一层
        maxsum[j]=a[i][j];
	}
	for(int i=n-1;i>=1;i--){//递推
        for(int j=1;j<=i;j++){
            maxsum[j]=max(maxsum[j],maxsum[j+1])+a[i][j];
        }
	}
	cout<<maxsum[1];//金字塔顶顶点
	return 0;
}
