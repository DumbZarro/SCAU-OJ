#include<iostream>
#include<iomanip>
#include<math.h>
#include<string>
#include<cstring>
using namespace std;
int f(int m,int n){
    if(n==1){//����ֻ��һ��
        return 1;
    }
    if(m<=1){//ƻ��ֻʣһ�������
        return 1;
    }
    if(m-n>=0){//ƻ����������
        return f(m,n-1)+f(m-n,n);//��n�����ӵ������ַŷ�+�������ӵķ���
        //ÿ�����ӷ�һ����ÿ�����Ӷ�������һ����
    }
    else{//ƻ����������
        return f(m,n-1);//��n�����ӵ������ַŷ� -1����һ������
    }
}

int main(){
    int x,i,m,n;//m��ƻ��,n������
    cin>>x;//��ȡ����
    for(i=1;i<=x;i++){
        cin>>m>>n;
        cout<<f(m,n)<<endl;
    }
    return 0;
}
