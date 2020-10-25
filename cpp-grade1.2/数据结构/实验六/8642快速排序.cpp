#include <iostream>
#include <cstdio>
using namespace std;

int part(int date[],int low,int high,int n) {//���һ�˿���,��������λ��
    date[0]=date[low];//��lowλ�õ�ֵ�ŵ��ڱ�
    int mid=date[low];
    while(low<high) {
        while(low<high&&date[high]>=mid)//�����ǰhigh��ֵ��mid�����Լ���ֱ���ҵ���midС��ֵ��λ��
            --high;
        date[low]=date[high];//����λ�õ�ֵ����lowλ��
        while(low<high&&date[low]<=mid)//�����ǰlow��ֵ��midС�����Լ���ֱ���ҵ���mid���ֵ��λ��
            low++;
        date[high]=date[low];//����λ�õ�ֵ����highλ��
    }
    date[low]=date[0];//���ڱ���ֵ����lowλ��
    for(int i=1; i<=n; i++)
        printf("%d ",date[i]);
    cout<<endl;
    return low;//����low����ʱ��low�Ѿ��仯�ˣ�����Ϊ�м�λ��
}/*�˺����У�low��high��ֵ�����п����ڱ仯��*/

void quick_sort(int date[],int low,int high,int n) {
    if(low<high) {
        int pivotloc=part(date,low,high,n);//
        quick_sort(date,low,pivotloc-1,n);//�ݹ齫������ߵ�����
        quick_sort(date,pivotloc+1,high,n);//�ݹ齫�����ұߵ�����
    }
}

int main() {
    int n;
    cin>>n;
    int date[n+5];//��������һ���Դ������
    for(int i=1; i<=n; i++)
        cin>>date[i];//¼������
    quick_sort(date,1,n,n);//����sort����
    return 0;
}
