#include<iostream>
using namespace std;
struct node {//�ռ�վ�ڵ�
    int a,b;//���꣬����
} space[250];
int OK;//�ж��ܲ��ܵ�
int N,L,M,S;
void  dfs(int money,int energy,int pos,int space_num) {
    //posΪ��ǰλ��,moneyΪ���е�Ǯ,energyΪ��ǰ����,space_numΪ����վ�����
    if(pos+energy>=L) {
        OK=1;
        return ;
    }
    for(int i=space_num+1; i<=N; i++) {
        if(money>=space[i].b&&energy>=space[i].a-pos) {//Ǯ��,���ܷɵĵ��Ϳ��Լ���
            dfs(money-space[i].b,M,space[i].a,i);
        }
    }
}
int main() {
    cin>>N>>L>>M>>S;//NΪ�ռ�վ����,LΪ�յ�����ֵ,M�������,SΪļ���˶���Ǯ
    for(int i=1; i<=N; i++)
        cin>>space[i].a>>space[i].b;
    if(M>=L)//�������ֱ��
        OK=1;
    else//������ֱ�ɾ������������
        dfs(S,M,0,0);

    if(OK)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
    return 0;
}
//�����������
