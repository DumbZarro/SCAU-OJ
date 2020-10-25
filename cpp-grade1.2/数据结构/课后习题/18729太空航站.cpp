/*
先根据坐标求出未插入太空航站时空间极差，
然后将空间站极差值从1枚举到最大的空间极差值，
此过程判断该空间极差是否满足所需的 太空航站的数量 <= k的条件，
如果满足那么该值就是所要求的值，停止枚举，输出答案。
由于该过程所要求的值是从小到大有序枚举的，
那么我们就可以通过二分搜索的办法进行加快寻找。
*/

#include<iostream>
#include<algorithm>
using namespace std;
int n,k,a[100005];//n为航站序号,k为插入数量
bool check(int x) {
    int count=0;//已经插入的空间站个数
    int i;
    for(i=2; i<=n&&count<=k; i++) { //当极差为x时计算需要插入多少个空间站
        int temp1=(a[i]-a[i-1])/x;
        int temp2=temp1*x;
        int temp3=a[i]-a[i-1];
        if(temp1==1&&temp2==temp3)//两点之间距离等于极差
            continue;
        else if(temp1==1&&temp2!=temp3)
        //两点之前距离大于极差,小于两倍(即插入之后产生两个小于极差的距离)
            count++;
        else if(temp1>1&&temp2!=temp3)
        //两点距离大于极差两倍,且不是整数倍
            count+=temp1;
        else if(temp1>1&&temp2==temp3)
        //两点距离大于极差两倍,且刚好是整数倍
            count+=temp1-1;
    }
    return count<=k;
}
int main() {
    ios::sync_with_stdio(false);
    int i,low,high,middle,best,maxlen=0;
    cin>>n>>k;
    for(i=1; i<=n; i++) {
        cin>>a[i];
        maxlen=max(maxlen,a[i]-a[i-1]);//找出最大极差
    }
    best=maxlen;
    low=1,high=maxlen;
    while(low<=high) {
        middle=(low+high)/2;
        if(check(middle)) { //判断当前极差是否满足条件；太空站数量小于等于k
            best=middle;
            high=middle-1;//在左半区间探索，是否有更小的区间极差
        } else {
            low=middle+1;//当前极差太小，不存在这样的一个k0,则在右半区间寻找大一点的值
        }

    }
    cout<<best<<endl;
    return 0;
}
