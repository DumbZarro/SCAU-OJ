#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    int cs,i,j,n,sqr,upLimit,lowLimit;
    long long sum;
    scanf("%d",&cs);
    for(i=0;i<cs;i++){
        sum=0;
        scanf("%d",&n);
        sqr=sqrt(n);
        for(j=1;j<=n/(sqr+1);j++){//开根后的数据
            sum+=n/j;
            //printf("sum %d\n",sum);
        }
        upLimit=n;
        for(j=1;j<=sqr;j++){//开根前的数据
            lowLimit = n/(j+1);
            //printf("up %d ",upLimit);
            //printf("low %d ",lowLimit);
            sum += j*(upLimit-lowLimit);
            //printf("sum %d\n",sum);
            upLimit = lowLimit;

        }
        printf("%lld\n",sum);
    }
    return 0;
}
