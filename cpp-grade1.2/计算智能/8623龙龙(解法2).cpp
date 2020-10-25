#include <stdio.h>

int main()
{
    int cs,c,i,j,tmp,n;
    long long sum;
    scanf("%d",&cs);
    for(c=0;c<cs;c++){
        sum=0;
        scanf("%d",&n);
        for(i=1,j=n;i<=j;i++){
            tmp = n/i;
            if(j==i){
                sum = sum + tmp;
                continue;
            }
            sum = sum + tmp + (j-tmp)*(i-1);
            j=tmp;
        }
        printf("%lld\n",sum);
    }
    return 0;
}
