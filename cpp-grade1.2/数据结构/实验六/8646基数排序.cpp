#include<iostream>
#include<vector>
typedef long long ll;
using namespace std;/**< 基数排序 */
vector<int> e[10];
int main() {
    ios::sync_with_stdio(0),cin.tie(0);
    int i,j,k,n,a[1005];
    cin>>n;
    for(i=1; i<=n; i++)
        cin>>a[i];
    for(k=1; k<=100; k*=10) {
        for(i=1; i<=n; i++) /**< 入袋 */
            e[a[i]/k%10].push_back(a[i]);
        int l=1;
        for(i=0; i<=9; i++) { /**< 回收 */
            for(j=0; j<e[i].size(); j++)
                a[l++]=e[i][j];
            e[i].clear(); /**< 清空口袋 */
        }
        for(i=1; i<=n; i++){
            char c = '0';//看题目输出样例要进行格式输出
            cout.width(3);//格式输出有可分为两种方法:cout的成员函数\流操作算子
            cout.fill(c);//这里使用的是cout成员函数
            cout<<a[i]<<' ';
        }
        cout<<endl;
    }
    return 0;
}

