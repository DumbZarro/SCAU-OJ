#include<iostream>
#include<cstdio>
using namespace std;
int main() {
    int t,n;
    scanf("%d",&n);
    int date[n];
    for(int i=0; i<n; i++)//¼������
        scanf("%d",&date[i]);
    for(int i=0; i<n-1; i++) {//�����������Ľ��бȽ�(n-1)��
        int min=i;
        for(int j=i+1; j<n; j++) {//Ѱ����С��ֵ��λ��
            if(date[min]>date[j]) {
                min=j;//�ҵ���minλ�õ�ֵ��С�ģ�����λ�ø���min
            }
        }
        t=date[i];
        date[i]=date[min];
        date[min]=t;//��date[i]����С��ֵ����
        for(int k=0; k<n; k++)//���ÿ��
            printf("%d ",date[k]);
        printf("\n");
    }
    return 0;
}
