#include<cstdio>
#include <cstdlib>
//���������õ��˶���?
int main(){
    double res,sum;
    int leave;
    int stay;
    int n;
    scanf("%d",&n);
    int a,b;
    scanf("%d%d",&a,&b);
    leave=a+b;
    for(int k=0;k<n-1;k++)
    {
        scanf("%d%d",&a,&b);
        stay=leave-a;
        //������Ҫע��stayС��0�����
        if(stay<0)
        {
            stay=0;
            leave=a+b;
        }
        else{
            leave=leave+b;
        }
        sum+=stay;
    }
    res=sum/n;
    printf("%.2f",res);
}
