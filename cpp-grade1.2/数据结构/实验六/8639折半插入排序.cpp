#include<iostream>
#include<algorithm>
using namespace std;
int d[200000];//����һ���㹻�������
void Travers(int n) {//��������
    for(int i=1; i<=n; i++)
        cout<<d[i]<<" ";
    cout<<endl;
}
int main() {
    int n;
    cin>>n;
    for(int i=1; i<=n; i++)//d[0]����ֵ�����ڱ�
        cin>>d[i];
    int low,high,mid;
    for(int i=2; i<=n; i++) {//�ӵڶ�������ʼ,ͬ����n-1��
        //i������Ҫ��ǰ����Ԫ�ص��±�
        d[0]=d[i];//�����������ڱ�λ��
        low=1;
        high=i-1;//�ź���ĳ���
        while(low<=high) {//���ֲ��Ҳ���ĵط�
            mid=(low+high)/2;//ȡ�м�λ��
            if(d[0]<d[mid])//����������м�ֵҪС�����ֵ��mid�����
                high=mid-1;
            else
                low=mid+1;
        }
        //��high����low,��Ϊelse
        for(int j=i-1; j>=high+1; j--)//����λ�õ�����ԭ����λ��ȫ��������
            d[j+1]=d[j];
        d[high+1]=d[0];//���ڱ�λ�õ��������λ��
        Travers(n);//ÿ�˱���
    }
    return 0;
}
