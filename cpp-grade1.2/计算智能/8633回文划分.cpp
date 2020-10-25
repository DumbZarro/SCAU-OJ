#include <iostream>
#include <cstring>
#include <cstdio>
#define LEN 1010
#define MIN(A,B) (A<B?A:B)
using namespace std;

// f[i]表示前i个字符的最小划分数,长度为n的字符串答案就是f[n];
// f[i] = min{ f[k] + 1 | 0 <= k < i, s[k+1, i]是回文串 }
int f[LEN], len;
char s[LEN];//回文串

bool judge(char *left, char *right){
	while (left < right) {
		if (*left == *right) {
			++left;
			--right;
		}
	}
	return left >= right;//如果是回文串的话返回ture
}

int F(int i){
	if(i==0){
		return 0;
	}
	if(!f[i]){// f[i]表示前i个字符的最小划分数
		f[i]=F(i-1);//递归
		for(int k=i-2;k>=0;k--){//第一个肯定是1但是不一定是最小划分数
			if(judge(s+k+1, s+i)){//判断k到i是否回文串回文串
				f[i]=MIN(f[i],F(k));//找出最小划分数
			}
		}
		f[i]++;
	}
	return f[i];
}

int main() {
	int T;
	scanf("%d", &T);
	for (int kase=0;kase<T;kase++){
		scanf("%s", s + 1);
		memset(f, 0, sizeof(f));
		len = strlen(s + 1);//获取回文串的长度
		printf("%d\n", F(len));
	}
	return 0;
}
