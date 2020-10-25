#include <stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
const int MAXN=500010;
long long ans;//������������Ƚϴ󣬱�����long long
int a[MAXN],b[MAXN],c[MAXN];

//���Ѿ��ź����left~mid,mid+1~right���й鲢
void merge(int *a,int left,int mid,int right)
{
    int i,j;
    i=0;
    for(j=left;j<=mid;j++)
       b[i++]=a[j];
    int len1=mid-left+1;
    i=0;
    for(j=mid+1;j<=right;j++)
       c[i++]=a[j];
    int len2=right-mid;
    i=0;
    j=0;
    int k=left;
    while(i<len1&&j<len2&&k<=right)
    {
        if(b[i]<=c[j])
        {
            a[k++]=b[i++];
        }
        else
        {
            a[k++]=c[j++];
            ans+=(len1-i);//�����������ۼӺ�����Լ�С�����ĸ���
            //��ʱb[i]>c[j],��ôc[j]���b[i]�����len1-i�������������
        }
    }
    while(i<len1) a[k++]=b[i++];
    while(j<len2) a[k++]=c[j++];
}
void merge_sort(int *a,int left,int right)//��a[left~right-1]���й鲢����
{
    if(left<right)
    {
        int mid=(left+right)/2;
        merge_sort(a,left,mid);
        merge_sort(a,mid+1,right);
        merge(a,left,mid,right);
    }
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n;
    while(scanf("%d",&n),n)
    {
        for(int i=0;i<n;i++)
          scanf("%d",&a[i]);
        ans=0;
        merge_sort(a,0,n-1);
        printf("%I64d\n",ans);
    }
    return 0;
}
