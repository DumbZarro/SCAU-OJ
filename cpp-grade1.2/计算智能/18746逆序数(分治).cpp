#include<iostream>
using namespace std;
int n,a[100005],temp[100005];//a��ԭ����,temp����ʱ����
long long sum=0;//ע�����������ݷ�Χ


void mergeSort(int left,int right) {//a��temp��sum����ȫ�ֱ������Բ��ô�
    if(right-left>1) {
        int mid = left+(right-left)/2;
        int temp_left=left,temp_right=mid,i=left;
        //temp_left��temp_right�ֱ�Ϊ�����������ϲ�����ı����ű�,iΪ�ϲ�������ı����ű�
        //����
        mergeSort(left,mid);
        mergeSort(mid,right);
        //�鲢
        while(temp_left<mid || temp_right<right) {
            if(temp_right>=right||(temp_left<mid&&a[temp_left]<=a[temp_right])) {
                temp[i++]=a[temp_left++];//[]�ͺ���++���ȼ���Ϊ1,����
            } else {
                temp[i++]=a[temp_right++];
                sum += mid-temp_left;//�ڹ鲢����Ļ����ϼ�����һ��
                //���������Ԫ��Ҫ��ǰ�ŵ�ʱ������������mid-temp_left����������,��������
            }//��ȷ"������������ֱ��������"�Ͳ��������һ������
        }
        for(i=left; i<right; i++) {//����ʱ���鸴�ƻ�ԭ����
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
