#include<iostream>
#include<vector>
typedef long long ll;
using namespace std;/**< �������� */
vector<int> e[10];
int main() {
    ios::sync_with_stdio(0),cin.tie(0);
    int i,j,k,n,a[1005];
    cin>>n;
    for(i=1; i<=n; i++)
        cin>>a[i];
    for(k=1; k<=100; k*=10) {
        for(i=1; i<=n; i++) /**< ��� */
            e[a[i]/k%10].push_back(a[i]);
        int l=1;
        for(i=0; i<=9; i++) { /**< ���� */
            for(j=0; j<e[i].size(); j++)
                a[l++]=e[i][j];
            e[i].clear(); /**< ��տڴ� */
        }
        for(i=1; i<=n; i++){
            char c = '0';//����Ŀ�������Ҫ���и�ʽ���
            cout.width(3);//��ʽ����пɷ�Ϊ���ַ���:cout�ĳ�Ա����\����������
            cout.fill(c);//����ʹ�õ���cout��Ա����
            cout<<a[i]<<' ';
        }
        cout<<endl;
    }
    return 0;
}

