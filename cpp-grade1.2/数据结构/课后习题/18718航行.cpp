#include<iostream>
using namespace std;
struct node {//空间站节点
    int a,b;//坐标，花费
} space[250];
int OK;//判断能不能到
int N,L,M,S;
void  dfs(int money,int energy,int pos,int space_num) {
    //pos为当前位置,money为现有的钱,energy为当前油量,space_num为加油站的序号
    if(pos+energy>=L) {
        OK=1;
        return ;
    }
    for(int i=space_num+1; i<=N; i++) {
        if(money>=space[i].b&&energy>=space[i].a-pos) {//钱够,且能飞的到就可以加油
            dfs(money-space[i].b,M,space[i].a,i);
        }
    }
}
int main() {
    cin>>N>>L>>M>>S;//N为空间站个数,L为终点坐标值,M最大油量,S为募集了多少钱
    for(int i=1; i<=N; i++)
        cin>>space[i].a>>space[i].b;
    if(M>=L)//如果可以直飞
        OK=1;
    else//不可以直飞就深度优先搜索
        dfs(S,M,0,0);

    if(OK)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
    return 0;
}
//深度优先搜索
