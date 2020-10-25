#include <iostream>
#include <algorithm>
using namespace std;
struct node {
    int x,y,s;//x为行，y为列，s为值
    bool operator < (const node &c) const { //重载大小排序的规则
        if(y==c.y)
            return x<c.x;//y相同，x值小的排在前面
        else
            return y<c.y;// y不同，y值小的排在前面
    }
} nodes[10005];
int main() {
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=0; i<k; i++)
        cin>>nodes[i].x>>nodes[i].y>>nodes[i].s;
    sort(nodes,nodes+k);//按照重载规则排序，即把三元组由按列优先转为按行优先的方式存储
    for(int i=0; i<k; i++)
        cout<<nodes[i].y<<" "<<nodes[i].x<<" "<<nodes[i].s<<endl;//交换x，y的输出顺序
    return 0;
}
