#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    int m;
    while(scanf("%d",&m)==1&&m) //��case������Ϊ0ʱ����
    {
        int a[5];//���ڴ洢��������5������
        int flag[10]={0};//�������Ƿ��ù��ı������
        for(a[0]=0;a[0]<=9;a[0]++)
        {
            flag[a[0]]=1;//���
            for(a[1]=0;a[1]<=9;a[1]++)
            {
                if(flag[a[1]]==1&&a[1]!=0)continue;//�ù��ļ������ã�0���ö��
                flag[a[1]]=1;          //���
                for(a[2]=0;a[2]<=9;a[2]++)
                {
                    if(flag[a[2]]==1&&a[2]!=0)continue;
                    flag[a[2]]=1;
                    for(a[3]=0;a[3]<=9;a[3]++)
                    {
                        if(flag[a[3]]==1&&a[3]!=0)continue;
                        flag[a[3]]=1;
                        for(a[4]=0;a[4]<=9;a[4]++)
                        {
                            if(flag[a[4]]==1&&a[4]!=0)continue;
                            flag[a[4]]=1;
                            int num=a[0]*10000+a[1]*1000+a[2]*100+a[3]*10+a[4];//a�����д��5�����ֻ�Ϊ5λ��
                            if(num%m==0)//����պÿ����������������е�����������
                            {
                                int result=num/m;
                                int tmp=result,i;
                                for(i=0;i<5;i++)//�жϳ����е�5�������Ƿ��ù���0���ö��
                                {
                                    int t=tmp%10;
                                    tmp=tmp/10;
                                    if(flag[t]!=0&&t!=0)break;
                                    flag[t]=1;
                                }
                                if(num!=0&&i>=5)//�����δ���ù��������
                                {
                                    printf("%05d/%05d=%d\n",num,result,m);
                                }
                                for(int j=0;j<i;j++)//���ñ������
                                {
                                    int t=result%10;
                                    result/=10;
                                    flag[t]=0;
                                }
                            }
                            flag[a[4]]=0;//��������4�ı�ǣ���ͬ
                        }
                        flag[a[3]]=0;
                    }
                    flag[a[2]]=0;
                }
                flag[a[1]]=0;
            }
             flag[a[0]]=0;
        }
       printf("\n");
    }
    return 0;
}
