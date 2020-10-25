#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
struct fruit{
	int a;//水果重量
	int b;//保质期
	bool operator < (const fruit &c) const{//运算符重载由大到小
		return a>c.a;
	}
}fruits[1005];
int main(){
	int n;
	cin>>n;
	int q[1005];
	memset(q,0,sizeof(q));
	for(int i=0;i<n;i++)
        cin>>fruits[i].a>>fruits[i].b;
	sort(fruits,fruits+n);//按照重量来排序,重的在前面
	int count=0;
	int Max=fruits[0].b;
	for(int i=1;i<n;i++){
		if(fruits[i].b>Max)
            Max=fruits[i].b;//算他可以吃几天
	}
	cout<<Max<<endl;
	//j是小于max
	//水果重量从大到小排,只要排满就是最优解
	//先遍历的肯定是大的,即使后面有同一天的都不选,因为后面的肯定小
	for(int i=0;i<n;i++){//每个水果遍历
		for(int j=fruits[i].b;j>=1;j--){//模拟每天
			if(q[j]==0){//第j天还没有吃水果
				 q[j]=fruits[i].a;//吃了就算重量
				 cout<<q[j]<<endl;
				 break;
			}
		}
	}
	for(int i=1;i<=Max;i++){//循环计算吃的总重量
		count+=q[i];
	}
	cout<<count<<endl;
}
