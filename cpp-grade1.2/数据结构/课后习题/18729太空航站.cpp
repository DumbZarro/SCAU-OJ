/*
�ȸ����������δ����̫�պ�վʱ�ռ伫�
Ȼ�󽫿ռ�վ����ֵ��1ö�ٵ����Ŀռ伫��ֵ��
�˹����жϸÿռ伫���Ƿ���������� ̫�պ�վ������ <= k��������
���������ô��ֵ������Ҫ���ֵ��ֹͣö�٣�����𰸡�
���ڸù�����Ҫ���ֵ�Ǵ�С��������ö�ٵģ�
��ô���ǾͿ���ͨ�����������İ취���мӿ�Ѱ�ҡ�
*/

#include<iostream>
#include<algorithm>
using namespace std;
int n,k,a[100005];//nΪ��վ���,kΪ��������
bool check(int x) {
    int count=0;//�Ѿ�����Ŀռ�վ����
    int i;
    for(i=2; i<=n&&count<=k; i++) { //������Ϊxʱ������Ҫ������ٸ��ռ�վ
        int temp1=(a[i]-a[i-1])/x;
        int temp2=temp1*x;
        int temp3=a[i]-a[i-1];
        if(temp1==1&&temp2==temp3)//����֮�������ڼ���
            continue;
        else if(temp1==1&&temp2!=temp3)
        //����֮ǰ������ڼ���,С������(������֮���������С�ڼ���ľ���)
            count++;
        else if(temp1>1&&temp2!=temp3)
        //���������ڼ�������,�Ҳ���������
            count+=temp1;
        else if(temp1>1&&temp2==temp3)
        //���������ڼ�������,�Ҹպ���������
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
        maxlen=max(maxlen,a[i]-a[i-1]);//�ҳ���󼫲�
    }
    best=maxlen;
    low=1,high=maxlen;
    while(low<=high) {
        middle=(low+high)/2;
        if(check(middle)) { //�жϵ�ǰ�����Ƿ�����������̫��վ����С�ڵ���k
            best=middle;
            high=middle-1;//���������̽�����Ƿ��и�С�����伫��
        } else {
            low=middle+1;//��ǰ����̫С��������������һ��k0,�����Ұ�����Ѱ�Ҵ�һ���ֵ
        }

    }
    cout<<best<<endl;
    return 0;
}
