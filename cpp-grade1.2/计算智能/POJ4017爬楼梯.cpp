#include <iostream>
using namespace std;
int N;
int stairs(int n)
{
    if (n==1)//剩下一阶有1种走法
        return 1;
    if (n==2)//剩下两阶有2种走法
        return 2;
    return stairs(n-1)+stairs(n-2);//当前走法等于两种走法加起来
}
int main()
{
    while (cin>>N) {
        cout<<stairs(N)<<endl;
    }
    return 0;
}
