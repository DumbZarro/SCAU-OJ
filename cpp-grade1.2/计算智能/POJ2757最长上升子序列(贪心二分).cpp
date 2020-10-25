#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn =300003, INF = 0x7f7f7f7f;
/*
int����4���ֽ� һ�����ֽ�8��λ 0x7f7f7f7f ��ʮ������
Ҳ����4��0x7f ,һ��0x7f ת��Ϊ�����ƾ��� 01111111
��Ϊ��int�� ��һ��λ�Ƿ���λ ���������int ���� 0x7f7f7f7fҲ������������˼
*/
//�������ó���������еĳ��Ⱥ�����Ԫ���ǿɿ���,���������ǲ��ɿ���

int low[maxn], a[maxn];
int n, ans;
int binary_search(int *a, int R, int x){//���ֲ��ң�����a�����е�һ��>=x��λ��
    int L = 1, mid;
    while(L <= R){
        mid = (L+R) >> 1;
        if(a[mid] <= x)
            L = mid + 1;
        else
            R = mid - 1;
    }
    return L;
}
int main(){
    scanf("%d", &n);
    for(int i=1; i<=n; i++){
        scanf("%d", &a[i]);
        low[i] = INF;   //����low�д������Сֵ������low��ʼ��ΪINF
    }
    low[1] = a[1];
    ans = 1;   //��ʼʱLIS����Ϊ1
    for(int i=2; i<=n; i++){
        if(a[i] > low[ans]){//��a[i]>=low[ans]��ֱ�Ӱ�a[i]�ӵ�����
            low[++ans] = a[i];
        }
        else{//�����ҵ�low�е�һ��>=a[i]��λ��low[j]����a[i]����low[j]
            low[binary_search(low, ans, a[i])] = a[i];
        }
    }
    printf("%d\n", ans);//�����
    return 0;
}


//c++�Ż�!!!
/*
#include<stdio.h>
#include<string.h>
#include<algorithm>

using namespace std;

int num[10]={3,6,3,2,4,6,7,5,4,3};

const int INF=0x3f3f3f3f;
int l=10, g[100], d[100];

int main()
{
    fill(g, g+l, INF);
    int max_=-1;
    for(int i=0; i<l; i++)
    {
        int j = lower_bound(g, g+l, num[i]) - g;
        d[i] = j+1;
        if(max_<d[i])
            max_=d[i];
        g[j] = num[i];
    }
    printf("%d\n", max_);
    return 0;
}

����㷨��ʵ�Ѿ�����DP�ˣ��е���̰�ġ����ڸ��ӶȽ�����ʵ����Ϊ����㷨�����õ��˶���������
������N����Ҫ������O(n)��ÿ�μ���Ҫ����N�λ���O(n)��һ������O(n^2)��
��������������O(logn)�Ķ����������ܵĸ��ӶȾͱ�ΪO(nlogn)�ˡ�
������Ҫע��һ��lower_bound������Ӧ�ã�ע���ȥ��g�ǵ�ַ��
��ַ - ��ַ = �±ꡣ
*/
