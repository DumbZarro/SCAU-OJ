#include<cstdio>
#include<cstdlib>
#include<cstring>
#define maxn 10010
int ap[maxn];
void swap(int &a,int &b) {
    int t=a;
    a=b;
    b=t;
}
//建立最大堆,由于每次取最大元素反正末尾，就相当于顺着按递增顺序排
void dot(int ap[],int i,int n) {
    int each,j,tmp=ap[i];
    for(j=i; j*2<=n; j=each) {
        each=j*2;
        if(each!=n&&ap[each]<ap[each+1])
            each++;
        if(tmp>ap[each])
            break;
        ap[j]=ap[each];
    }
    ap[j]=tmp;
}
int main() {
    int i,n;
    scanf("%d",&n);
    for(i=1; i<=n; i++) {
        scanf("%d",&ap[i]);
    }
    //建堆
    for(int i=n/2; i>0; i--) {
        dot(ap,i,n);
    }
    for(int i=n; i>=1; i--) {
        for(int t=1; t<=n; t++)
            printf("%d ",ap[t]);
        printf("\n");
        swap(ap[1],ap[i]);
        dot(ap,1,i-1);
    }
    return 0;
}
