#include<iostream>
#include<algorithm>// ��Ϊ�õ���sort
using namespace std;
int eDragon[200005],warrior[200005];
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int n=1,m=1,i;//�жϽ���Ϊ00,Ϊ�˷�ֹ������䵽0,�趨Ϊ1
    while((cin>>n>>m)&&n&&m){//��������
        for(i=0;i<n;i++){
            cin>>eDragon[i];
        }
        for(i=0;i<m;i++){
            cin>>warrior[i];
        }
        //����
        sort(eDragon,eDragon+n);
        sort(warrior,warrior+m);
        int now=0;//Ҫ�����������
        int cost=0;// ��ǰ�ܷ���
        for(i=0;i<m;i++){//����
            if(warrior[i]>=eDragon[now]){
                cost += warrior[i];//��Ӷ����ʿ
                if(++now==n){
                    break;//�����������,�˳�ѭ��
                }
            }
        }
        if(now<n){//�����û����
            cout<<"Loowater is doomed!\n";
        }
        else{
            cout<<cost<<endl;
        }
    }
    return 0;
}
