#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
struct fruit{
	int a;//ˮ������
	int b;//������
	bool operator < (const fruit &c) const{//����������ɴ�С
		return a>c.a;
	}
}fruits[1005];
int main(){
	int n;
	cin>>n;
	int q[1005];
	memset(q,0,sizeof(q));
	for(int i=0;i<n;i++)
        cin>>fruits[i].a>>fruits[i].b;
	sort(fruits,fruits+n);//��������������,�ص���ǰ��
	int count=0;
	int Max=fruits[0].b;
	for(int i=1;i<n;i++){
		if(fruits[i].b>Max)
            Max=fruits[i].b;//�������ԳԼ���
	}
	cout<<Max<<endl;
	//j��С��max
	//ˮ�������Ӵ�С��,ֻҪ�����������Ž�
	//�ȱ����Ŀ϶��Ǵ��,��ʹ������ͬһ��Ķ���ѡ,��Ϊ����Ŀ϶�С
	for(int i=0;i<n;i++){//ÿ��ˮ������
		for(int j=fruits[i].b;j>=1;j--){//ģ��ÿ��
			if(q[j]==0){//��j�컹û�г�ˮ��
				 q[j]=fruits[i].a;//���˾�������
				 cout<<q[j]<<endl;
				 break;
			}
		}
	}
	for(int i=1;i<=Max;i++){//ѭ������Ե�������
		count+=q[i];
	}
	cout<<count<<endl;
}
