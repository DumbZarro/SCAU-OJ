#include<iostream>
#include<cstdio>
using namespace std;
int main() {
    int t,n;
    scanf("%d",&n);
    int date[n];
    for(int i=0; i<n; i++)//录入数据
        scanf("%d",&date[i]);
    for(int i=0; i<n-1; i++) {//将其与其后面的进行比较(n-1)趟
        int min=i;
        for(int j=i+1; j<n; j++) {//寻找最小的值的位置
            if(date[min]>date[j]) {
                min=j;//找到比min位置的值更小的，将其位置赋予min
            }
        }
        t=date[i];
        date[i]=date[min];
        date[min]=t;//将date[i]与最小的值交换
        for(int k=0; k<n; k++)//输出每趟
            printf("%d ",date[k]);
        printf("\n");
    }
    return 0;
}
