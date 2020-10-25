#include<cstdio>
#include<algorithm>
using namespace std;
struct data{
    int num;//通过题数
    int time;//罚时
    int order;//输入顺序
    char name[21];//成员名字
};
data A[500000];//定义一个结构体数组，如果定义在函数里面会爆掉，申请的空间太大了

int comp(data &a,data &b){//建立一个符合题意的排序规则
    if(a.num==b.num){//如果通过题数相等
        if(a.time==b.time){//如果罚时相等
            return a.order<b.order;//先输入的在前面
        }
        else{
            return a.time<b.time;//罚时不相等，罚时少的在前面
        }
    }
    else{
        return a.num>b.num;//如果通过题数不相等，则通过题数多的在前面
    }
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d%d%s",&A[i].num,&A[i].time,&A[i].name);
        A[i].order=i+1;
    }
    sort(A,A+n,comp);//以comp的规则来进行排序
    for(int i=0;i<n;i++){
        printf("%s\n",A[i].name);//将排好的输出
    }
    return  0;
}
