#include<cstdio>
#include<algorithm>
using namespace std;
struct data{
    int num;//ͨ������
    int time;//��ʱ
    int order;//����˳��
    char name[21];//��Ա����
};
data A[500000];//����һ���ṹ�����飬��������ں�������ᱬ��������Ŀռ�̫����

int comp(data &a,data &b){//����һ������������������
    if(a.num==b.num){//���ͨ���������
        if(a.time==b.time){//�����ʱ���
            return a.order<b.order;//���������ǰ��
        }
        else{
            return a.time<b.time;//��ʱ����ȣ���ʱ�ٵ���ǰ��
        }
    }
    else{
        return a.num>b.num;//���ͨ����������ȣ���ͨ�����������ǰ��
    }
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d%d%s",&A[i].num,&A[i].time,&A[i].name);
        A[i].order=i+1;
    }
    sort(A,A+n,comp);//��comp�Ĺ�������������
    for(int i=0;i<n;i++){
        printf("%s\n",A[i].name);//���źõ����
    }
    return  0;
}
