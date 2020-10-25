#include <iostream>
#include <cstring>
#include <cstdio>
#define LEN 1010
#define MIN(A,B) (A<B?A:B)
using namespace std;

// f[i]��ʾǰi���ַ�����С������,����Ϊn���ַ����𰸾���f[n];
// f[i] = min{ f[k] + 1 | 0 <= k < i, s[k+1, i]�ǻ��Ĵ� }
int f[LEN], len;
char s[LEN];//���Ĵ�

bool judge(char *left, char *right){
	while (left < right) {
		if (*left == *right) {
			++left;
			--right;
		}
	}
	return left >= right;//����ǻ��Ĵ��Ļ�����ture
}

int F(int i){
	if(i==0){
		return 0;
	}
	if(!f[i]){// f[i]��ʾǰi���ַ�����С������
		f[i]=F(i-1);//�ݹ�
		for(int k=i-2;k>=0;k--){//��һ���϶���1���ǲ�һ������С������
			if(judge(s+k+1, s+i)){//�ж�k��i�Ƿ���Ĵ����Ĵ�
				f[i]=MIN(f[i],F(k));//�ҳ���С������
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
		len = strlen(s + 1);//��ȡ���Ĵ��ĳ���
		printf("%d\n", F(len));
	}
	return 0;
}
