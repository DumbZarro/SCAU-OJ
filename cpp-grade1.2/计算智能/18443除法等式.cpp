#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    int m;
    while(scanf("%d",&m)==1&&m) //多case，输入为0时结束
    {
        int a[5];//用于存储被除数的5个数字
        int flag[10]={0};//该数字是否被用过的标记数组
        for(a[0]=0;a[0]<=9;a[0]++)
        {
            flag[a[0]]=1;//标记
            for(a[1]=0;a[1]<=9;a[1]++)
            {
                if(flag[a[1]]==1&&a[1]!=0)continue;//用过的即不再用，0可用多次
                flag[a[1]]=1;          //标记
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
                            int num=a[0]*10000+a[1]*1000+a[2]*100+a[3]*10+a[4];//a数组中存的5个数字化为5位数
                            if(num%m==0)//如果刚好可以整除，即满题中的整除的条件
                            {
                                int result=num/m;
                                int tmp=result,i;
                                for(i=0;i<5;i++)//判断除数中的5个数字是否被用过，0可用多次
                                {
                                    int t=tmp%10;
                                    tmp=tmp/10;
                                    if(flag[t]!=0&&t!=0)break;
                                    flag[t]=1;
                                }
                                if(num!=0&&i>=5)//如果都未被用过，则输出
                                {
                                    printf("%05d/%05d=%d\n",num,result,m);
                                }
                                for(int j=0;j<i;j++)//重置标记数组
                                {
                                    int t=result%10;
                                    result/=10;
                                    flag[t]=0;
                                }
                            }
                            flag[a[4]]=0;//重置数字4的标记，下同
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
