#include<iostream>//�鲢�����Ȳ���
#include<cstring>
int a[1500];
using namespace std;
void hebing(int *a,int l,int mid,int r)//�ϲ�,��a������±�l��r�м�Ϊm�Ĳ��ֺϲ�
{
	int b[1500];//��ʱ��źϲ���������飬����a�������
	memset(b,0,sizeof(int)) ;//����b����
	int k=0;
	int i=l;int j=mid;
	while(i<mid&&j<=r)//��mid���������˶�ʣ����ʱ������һ�߷����˶����˳�
	{
		if(a[i]<=a[j])//С����ǰ��
			b[k++]=a[i++];
		else
			b[k++]=a[j++];
	}
	while(j<=r) b[k++]=a[j++];//ע����һ�������һ��һ��ֻ�ϲ���������һ��ִ��
	while(i<mid) b[k++]=a[i++];//��ʣ�µ�û�����һ��Ҳ�ӽ�b����
	for(int i=l;i<=r;i++) a[i]=b[i-l];//��b����a
}

void guibing(int *a,int start,int end){//��� (ԭ���ҿ�����Ӣ�
//��ע�����Ǹ��ݹ飩
	if(start==end) return;//����С�����ٲ�
	int mid=(start+end)/2;
	guibing(a,start,mid);//�����
	guibing(a,mid+1,end);//���ұ�
	hebing(a,start,mid+1,end);//�ϲ�
}
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	guibing(a,1,n);
	for(int i=1;i<=n;i++)
		cout<<a[i]<<" ";
	return 0;
 }
