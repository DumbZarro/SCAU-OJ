#include<iostream>
using namespace std;

void Process(int n);
void MergeSort(int ori[],int n);
void newMerge(int ori[],int tmpArray[],int s,int n);
//û����������鲢ʱ������������鲢�������ڵ������������
void Merge(int ori[],int tmpArray[],int left,int mid,int right);
//�鲢�������ź�������鵽tmpArray��
void Output(int op[],int n);//�����������

int main(){
    int n;//���Ÿ���
    cin >> n;
    Process(n);
    return 0;
}

void Process(int n){
    int ori[n+1];//ԭ����
    for(int i = 1; i <= n; ++i){//��ȡԭ����
        cin >> ori[i];
    }
    if( n > 1){//�����ֹһ������Ԫ�أ��͹鲢
        MergeSort(ori,n);//ԭʼ���� MergeSort
    }
    else{
        Output(ori,n);
    }
}

void MergeSort(int ori[],int n){//��ԭ�����з�(�����õ��ǵ���)
    int s = 1,tmpArray[n+1];
    //s��ÿ�˹鲢��������ʱ��һ������ĳ���(����Ǹ����鳤�ȿ���С��s)
    while(s < n){
        newMerge(ori,tmpArray,s,n);
        s *= 2;
    }
}

void newMerge(int ori[],int tmpArray[],int s,int n){
    //û����������鲢ʱ������������鲢�������ڵ������������
    int i = 1;
    while(i <= n- 2*s + 1){//���� i + 2s - 1 <= n���Եó�
        Merge(ori, tmpArray, i, i+s-1, i+2*s-1);
        i += 2*s;
    }
    if(i<=n-s){//�����������У������Ǹ��ĳ��Ȳ���s��
        Merge(ori, tmpArray, i, i+s-1, n);
    }
    else{//���鲢�����ֻʣһ�����Ȳ���s���ˣ�ֻ��ֱ�Ӹ��Ƶ�tmpArray[]��
        for(;i<=n;++i){
            tmpArray[i] = ori[i];
        }
    }
    //���ˣ����һ�˹鲢
    //��copy��ori[]�� ,to code here
    for(int k = 0; k <= n; ++k){
        ori[k] = tmpArray[k];
    }
    Output(ori,n);
}

void Merge(int ori[],int tmpArray[],int left,int mid,int right){
    //�鲢�������ź�������鵽tmpArray[]��,Ȼ����copy��ori[]��
    int tmpCnt = left; //��ʱ������
    int rightStart = mid + 1; // mid��ʵ��leftEnd
    while(left <= mid && rightStart <= right){
        if(ori[left] <= ori[rightStart])
            tmpArray[tmpCnt++] = ori[left++];
        else
            tmpArray[tmpCnt++] = ori[rightStart++];
    }
    //����Ϊ˭�ж�Ͱ�˭ֱ�ӷŵ�tmpArray[]��
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
