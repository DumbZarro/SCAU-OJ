#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct fruit {
    int w;
    int t;
};
int compare(const void *a,const void *b) {
    return ((struct fruit *)b)->w-((struct fruit *)a)->w;
}
int n,eat[1000],sum;
struct fruit data[1000];

int main() {
    int i,k;
    scanf("%d",&n);
    memset(eat,0,sizeof(eat));
    for(i=0; i<n; i++)
        scanf("%d%d",&data[i].w,&data[i].t);
////////////////////解释从这开始//////////////////////////
    qsort(data,n,sizeof(struct fruit),compare);
    for(i=0; i<n; i++) {
        k=data[i].t;
        while(k&&eat[k]!=0)
            --k;
        if(k)
            eat[k]=data[i].w;
    }
    for(i=0,sum=0; i<n; i++)
        sum+=eat[i];
/////////////////////解释到这结束///////////////////////////
    printf("%d",sum);
    return 0;
}
