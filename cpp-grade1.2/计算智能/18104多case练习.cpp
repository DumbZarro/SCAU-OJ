#include <iostream>
#include <cstdio>
using namespace std;
long long dfs(long long a,long long b) {    //��Ϊ��Ŀ����������Ϊ2��31�η�����Ҫ��long long
    long long c,q,p;
    q=a;
    p=b;
    while(a%b!=0) {                         //շת����������Լ��
        c=a%b;
        a=b;
        b=c;
    }
    return (p*q)/b;                         //ԭ��������ֵ��˳�ȥ���Լ��������С������
}


int main() {
    int n,a,b;
    scanf("%d",&n);
    while(n--) {                            //��һ���case�����ֱ��n�Լ�����
        cin>>a>>b;
        cout<<dfs(a,b)<<endl;
    }
    cout<<"group 1 done"<<endl;
    while(cin>>a>>b&&a&&b)                  //�ڶ��ֶ�case�������Ҫ�����a��bΪ�ж�����
        cout<<dfs(a,b)<<endl;
    cout<<"group 2 done"<<endl;
    while(cin>>a>>b)                        //�������ޱ�־��case����Ҫ����ʱ�������ctrl+z���ɽ������൱������cin>>a>>b=EOF
        cout<<dfs(a,b)<<endl;
    cout<<"group 3 done"<<endl;
    return 0;
}
