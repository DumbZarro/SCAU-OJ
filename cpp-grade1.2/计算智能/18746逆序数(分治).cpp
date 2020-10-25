#include<iostream>
using namespace std;
int n,a[100005],temp[100005];//a是原数组,temp是临时数组
long long sum=0;//注意逆序数数据范围


void mergeSort(int left,int right) {//a、temp、sum都是全局变量可以不用传
    if(right-left>1) {
        int mid = left+(right-left)/2;
        int temp_left=left,temp_right=mid,i=left;
        //temp_left和temp_right分别为左右两个待合并数组的遍历脚标,i为合并后数组的遍历脚标
        //分治
        mergeSort(left,mid);
        mergeSort(mid,right);
        //归并
        while(temp_left<mid || temp_right<right) {
            if(temp_right>=right||(temp_left<mid&&a[temp_left]<=a[temp_right])) {
                temp[i++]=a[temp_left++];//[]和后置++优先级都为1,左结合
            } else {
                temp[i++]=a[temp_right++];
                sum += mid-temp_left;//在归并排序的基础上加上这一句
                //当右数组的元素要往前排的时候左数组中有mid-temp_left个数比他大,构成逆序
            }//明确"左右两个数组分别都是有序的"就不难理解这一方法了
        }
        for(i=left; i<right; i++) {//从临时数组复制回原数组
            a[i]=temp[i];
        }
    }
}

int main() {
    ios::sync_with_stdio(0),cin.tie(0);
    int i;
    cin>>n;
    for(i=0; i<n; i++) {
        cin>>a[i];
    }
    mergeSort(0,n);
    cout<<sum;
    return 0;
}
