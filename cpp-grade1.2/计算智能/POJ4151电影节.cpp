#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

struct node{
    int begin,end;//��¼��ʼʱ��ͽ���ʱ��
}a[105];

int cmp(node a,node b){
    return a.end<b.end;//������ʱ����С��������
}

int main(){
    int t;
    while((cin>>t)&&(t!=0)){//��������
        for(int i=0;i<t;i++){
            scanf("%d%d",&a[i].begin,&a[i].end);//������������
        }
        sort(a,a+t,cmp);//����
        int sum=1;//���ٿ��ĵ�Ӱ��϶���1
        int js;//��ʾ����ʱ��
        js=a[0].end;
        for(int i=1;i<t;i++){//���α���
            if(a[i].begin>=js){//�����һ����ʼ��ʱ������һ������ʱ��֮�󣬾�����Ҫ��
                js=a[i].end;//���½���ʱ���ֵ
                sum++;//���Կ���Ӱ�ĸ���+1
            }
        }
        printf("%d\n",sum);
    }
}
