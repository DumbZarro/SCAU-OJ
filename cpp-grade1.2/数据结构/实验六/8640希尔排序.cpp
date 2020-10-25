#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
int dlta[100];
int num[100];
int n;
void get_dlta(int n) {
    n=(n>>1);//���Զ�����˼
    int i=0;
    while(n) {
        dlta[i++]=n;
        n=(n>>1);
    }
}
void traverse() {
    for(int i=1; i<=n; i++)
        cout<<num[i]<<" ";
    cout<<'\n';
}
void shell_sort() {
    int cur=0;
    while(dlta[cur]!=0) {
        for(int i=dlta[cur]+1; i<=n; i++) {//����һ����������
            num[0]=num[i];
            if(num[i]<num[i-dlta[cur]]) {
                int j;
                for(j=i-dlta[cur]; j>0&&(num[0]<num[j]); j-=dlta[cur])//���������ͬ����
                    num[j+dlta[cur]]=num[j];
                num[j+dlta[cur]]=num[0];
            }
        }
        traverse();
        cur++;
    }
}
int main() {
    cin>>n;
    get_dlta(n);//��ȡ����
    for(int i=1; i<=n; i++)//��ȡ��������
        cin>>num[i];
    shell_sort();
    return 0;
}
