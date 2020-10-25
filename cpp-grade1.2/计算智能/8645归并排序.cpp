#include<iostream>
using namespace std;

void Process(int n);
void MergeSort(int ori[],int n);
void newMerge(int ori[],int tmpArray[],int s,int n);
//没有完成整个归并时，用这个函数归并两个相邻的已排序的数组
void Merge(int ori[],int tmpArray[],int left,int mid,int right);
//归并两个已排好序的数组到tmpArray中
void Output(int op[],int n);//用来输出数组

int main(){
    int n;//待排个数
    cin >> n;
    Process(n);
    return 0;
}

void Process(int n){
    int ori[n+1];//原数组
    for(int i = 1; i <= n; ++i){//读取原数组
        cin >> ori[i];
    }
    if( n > 1){//如果不止一个待排元素，就归并
        MergeSort(ori,n);//原始调用 MergeSort
    }
    else{
        Output(ori,n);
    }
}

void MergeSort(int ori[],int n){//把原数组切分(这里用的是递推)
    int s = 1,tmpArray[n+1];
    //s是每趟归并两个数组时，一个数组的长度(最后那个数组长度可能小于s)
    while(s < n){
        newMerge(ori,tmpArray,s,n);
        s *= 2;
    }
}

void newMerge(int ori[],int tmpArray[],int s,int n){
    //没有完成整个归并时，用这个函数归并两个相邻的已排序的数组
    int i = 1;
    while(i <= n- 2*s + 1){//利用 i + 2s - 1 <= n可以得出
        Merge(ori, tmpArray, i, i+s-1, i+2*s-1);
        i += 2*s;
    }
    if(i<=n-s){//即最后的两个中，后面那个的长度不够s了
        Merge(ori, tmpArray, i, i+s-1, n);
    }
    else{//即归并到最后，只剩一个长度不够s的了，只需直接复制到tmpArray[]中
        for(;i<=n;++i){
            tmpArray[i] = ori[i];
        }
    }
    //至此，完成一趟归并
    //再copy回ori[]中 ,to code here
    for(int k = 0; k <= n; ++k){
        ori[k] = tmpArray[k];
    }
    Output(ori,n);
}

void Merge(int ori[],int tmpArray[],int left,int mid,int right){
    //归并两个已排好序的数组到tmpArray[]中,然后再copy回ori[]中
    int tmpCnt = left; //临时计数器
    int rightStart = mid + 1; // mid其实是leftEnd
    while(left <= mid && rightStart <= right){
        if(ori[left] <= ori[rightStart])
            tmpArray[tmpCnt++] = ori[left++];
        else
            tmpArray[tmpCnt++] = ori[rightStart++];
    }
    //下面为谁有多就把谁直接放到tmpArray[]中
    while(left <= mid){
        tmpArray[tmpCnt++] = ori[left++];
    }
    while(rightStart <= right){
        tmpArray[tmpCnt++] = ori[rightStart++];
    }
}
void Output(int op[],int n){
    for(int i = 1; i <= n; ++i)
    cout << op[i] << " ";
    cout << endl;
}
