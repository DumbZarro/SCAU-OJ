#include<iostream>
#include<algorithm>
using namespace std;
int d[200000];//定义一个足够大的数组
void Travers(int n) {//遍历函数
    for(int i=1; i<=n; i++)
        cout<<d[i]<<" ";
    cout<<endl;
}
int main() {
    int n;
    cin>>n;
    for(int i=1; i<=n; i++)//d[0]不赋值，做哨兵
        cin>>d[i];
    int low,high,mid;
    for(int i=2; i<=n; i++) {//从第二个数开始,同样是n-1趟
        //i代表需要当前排序元素的下标
        d[0]=d[i];//将该数放入哨兵位置
        low=1;
        high=i-1;//排好序的长度
        while(low<=high) {//二分查找插入的地方
            mid=(low+high)/2;//取中间位置
            if(d[0]<d[mid])//如果该数比中间值要小，则该值在mid的左边
                high=mid-1;
            else
                low=mid+1;
        }
        //用high不用low,因为else
        for(int j=i-1; j>=high+1; j--)//将该位置到该数原来的位置全部往右移
            d[j+1]=d[j];
        d[high+1]=d[0];//将哨兵位置的数插入此位置
        Travers(n);//每趟遍历
    }
    return 0;
}
