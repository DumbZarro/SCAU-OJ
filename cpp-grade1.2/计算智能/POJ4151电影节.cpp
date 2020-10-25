#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

struct node{
    int begin,end;//记录开始时间和结束时间
}a[105];

int cmp(node a,node b){
    return a.end<b.end;//按结束时间由小到大排序
}

int main(){
    int t;
    while((cin>>t)&&(t!=0)){//数据组数
        for(int i=0;i<t;i++){
            scanf("%d%d",&a[i].begin,&a[i].end);//依次输入数据
        }
        sort(a,a+t,cmp);//排序
        int sum=1;//最少看的电影书肯定是1
        int js;//表示结束时间
        js=a[0].end;
        for(int i=1;i<t;i++){//依次遍历
            if(a[i].begin>=js){//如果下一场开始的时间在这一场结束时间之后，就满足要求
                js=a[i].end;//更新结束时间的值
                sum++;//可以看电影的个数+1
            }
        }
        printf("%d\n",sum);
    }
}
