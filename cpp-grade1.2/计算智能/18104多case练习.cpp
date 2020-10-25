#include <iostream>
#include <cstdio>
using namespace std;
long long dfs(long long a,long long b) {    //因为题目输入的数最大为2的31次方，故要用long long
    long long c,q,p;
    q=a;
    p=b;
    while(a%b!=0) {                         //辗转相除法求最大公约数
        c=a%b;
        a=b;
        b=c;
    }
    return (p*q)/b;                         //原来的两个值相乘除去最大公约数就是最小公倍数
}


int main() {
    int n,a,b;
    scanf("%d",&n);
    while(n--) {                            //第一组多case情况，直接n自减即可
        cin>>a>>b;
        cout<<dfs(a,b)<<endl;
    }
    cout<<"group 1 done"<<endl;
    while(cin>>a>>b&&a&&b)                  //第二种多case情况，需要添加以a、b为判断条件
        cout<<dfs(a,b)<<endl;
    cout<<"group 2 done"<<endl;
    while(cin>>a>>b)                        //第三种无标志多case，想要结束时在命令窗口ctrl+z即可结束，相当于输入cin>>a>>b=EOF
        cout<<dfs(a,b)<<endl;
    cout<<"group 3 done"<<endl;
    return 0;
}
