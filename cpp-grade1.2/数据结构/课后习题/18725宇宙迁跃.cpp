/*
基本思路是将跃迁能力从小到大枚举，知道发现一个跃迁能力x可以满足条件，
可以知道跃迁能力是从1到an的一个序列。
由于这些特征我们可以利用二分查找的方法加快找到跃迁能力x。
设边界low=1,high=an；middle=(low+high)/2;
看看跃迁能力是否符合题目要求（此处是一个模拟过程），如果满足的话，先记录这个能力，
然后在左半区间继续探索；如果不符合要求的话，说明这个跃迁能力太小了，
我们要增大这个跃迁能力，于是我们从右半区间继续探索。
*/

#include<iostream>
using namespace std;
int a[10005],n,k;//n是坐标个数,a是坐标数组,k是限定的时间
bool judge(int x) { //判断能力x能否使飞船在k天内到达首都
    int i,cur_day=0,pre_pos=0;
    for(i=1; i<=n&&cur_day<=k; i++) {
        if(a[i]-a[i-1]>x)
            return false;
        if(x>=a[i]-pre_pos)//当前能力可以走到a[i]，看看能不能走到下一个
            continue;
        else {
            cur_day++;//时间增加一天
            pre_pos=a[i-1];//下一次的出发位置
            i--;//回退
        }
    }
    cur_day++;//最后位置的时间没有加上
    return cur_day<=k;//判断
}

int main() {
    ios::sync_with_stdio(false);
    int i;
    cin>>n>>k;
    for(i=1; i<=n; i++)
        cin>>a[i];
    int low=1,high=a[n],middle,best=a[n];
    while(low<=high) {//二分查找
        middle=(low+high)/2;
        if(judge(middle)) {
            best=middle;//记录跃迁能力
            high=middle-1;//看看是否还有更小的跃迁能力也可以使其成立
        }
        else
            low=middle+1;
    }
    cout<<best;
    return 0;
}
