/*
����˼·�ǽ�ԾǨ������С����ö�٣�֪������һ��ԾǨ����x��������������
����֪��ԾǨ�����Ǵ�1��an��һ�����С�
������Щ�������ǿ������ö��ֲ��ҵķ����ӿ��ҵ�ԾǨ����x��
��߽�low=1,high=an��middle=(low+high)/2;
����ԾǨ�����Ƿ������ĿҪ�󣨴˴���һ��ģ����̣����������Ļ����ȼ�¼���������
Ȼ��������������̽�������������Ҫ��Ļ���˵�����ԾǨ����̫С�ˣ�
����Ҫ�������ԾǨ�������������Ǵ��Ұ��������̽����
*/

#include<iostream>
using namespace std;
int a[10005],n,k;//n���������,a����������,k���޶���ʱ��
bool judge(int x) { //�ж�����x�ܷ�ʹ�ɴ���k���ڵ����׶�
    int i,cur_day=0,pre_pos=0;
    for(i=1; i<=n&&cur_day<=k; i++) {
        if(a[i]-a[i-1]>x)
            return false;
        if(x>=a[i]-pre_pos)//��ǰ���������ߵ�a[i]�������ܲ����ߵ���һ��
            continue;
        else {
            cur_day++;//ʱ������һ��
            pre_pos=a[i-1];//��һ�εĳ���λ��
            i--;//����
        }
    }
    cur_day++;//���λ�õ�ʱ��û�м���
    return cur_day<=k;//�ж�
}

int main() {
    ios::sync_with_stdio(false);
    int i;
    cin>>n>>k;
    for(i=1; i<=n; i++)
        cin>>a[i];
    int low=1,high=a[n],middle,best=a[n];
    while(low<=high) {//���ֲ���
        middle=(low+high)/2;
        if(judge(middle)) {
            best=middle;//��¼ԾǨ����
            high=middle-1;//�����Ƿ��и�С��ԾǨ����Ҳ����ʹ�����
        }
        else
            low=middle+1;
    }
    cout<<best;
    return 0;
}
