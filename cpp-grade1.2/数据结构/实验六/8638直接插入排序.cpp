#include<iostream>
#include<algorithm>
using namespace std;
int d[200000];//����һ���㹻���ȫ������
void Travers(int n) {//��������
    for(int i=0; i<n; i++)
        cout<<d[i]<<" ";
    cout<<endl;
}
int main() {
    int n;
    cin>>n;//nΪ���Ÿ���
    for(int i=0; i<n; i++)
        cin>>d[i];
    for(int  i=0; i<n-1; i++) {//��ʼ�������г���Ϊ1,�ܹ���Ҫ����n-1��
        if(d[i]>d[i+1]) {//������ұߵıȽ�С
            int t=d[i+1],j;
            for(j=i+1; j>0; j--) {//����λ��֮ǰ�������ƶ�
                if(t<d[j-1])
                    d[j]=d[j-1];
                else//ֱ����������С�������������ƶ�,����ѭ��
                    break;
            }
            d[j]=t;//�������赱ǰλ��,�ǵ÷�����(����tΪ��С�����)
        }
        Travers(n);//ÿ�˱���
    }
    return 0;
}
