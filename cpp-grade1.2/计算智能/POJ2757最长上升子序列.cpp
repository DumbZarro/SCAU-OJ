#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN =1010;
int a[MAXN];//������
int maxLen[MAXN];//�����iΪ�յ������������г���

int main(){
    int N;
    cin >> N;//��ȡ���г�
    for( int i = 1;i <= N;++i){//��ȡ�������ҳ�ʼ��������
         cin >> a[i];
         maxLen[i] = 1;
    }
    for( int i = 2; i <= N; ++i){
         for( int j = 1; j < i; ++j){//ÿ�����Ե�i����Ϊ�յ������������еĳ���
            //��������г��ȶԱ�
            if(a[i]>a[j]){//j<i
                maxLen[i] = max(maxLen[i],maxLen[j]+1);
            }
         }
    }
    cout<< * max_element(maxLen+1,maxLen + N + 1 );//�����������ֵ(first,end),�ǵü�*
    return 0;
}//n**2
