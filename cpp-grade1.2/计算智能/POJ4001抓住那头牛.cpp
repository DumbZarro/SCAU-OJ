#include <iostream>
#include <queue>
#include <cstdio>
using namespace std;

int N, K;//农夫起始位于点N(0<=N<=100000)，牛位于点K(0<=K<=100000)
int vis[201000];//有2x的选择,所以要开到2*100000以上的大小

struct point {
    int pos;
    int step;
    point(int p, int s) { //构造函数....
        pos = p;
        step = s;
    }
};

int main() {
    scanf("%d%d", &N, &K);
    queue<point> q;//创建队伍
    q.push(point(N, 0));//农夫初始位置入队
    int end_step = -1;//初始化最终步数
    while(!q.empty()) {
        point this_pos = q.front();//读取队头
        q.pop();//弹出队头
        int x=this_pos.pos, step=this_pos.step;
        if(x == K) { //如果当前位置等于牛的位置
            end_step = step;
            break;
        }
        if(x-1>=0 && x-1<=100000 && vis[x-1]==0) { //向后一步的点在范围内且没有走过
            q.push(point(x-1, step+1));
            vis[x-1] = 1;
        }
        if(x+1>=0 && x+1<=100000 && vis[x+1]==0) { //向前一步的点在范围内且没有走过
            q.push(point(x+1, step+1));
            vis[x+1] = 1;
        }
        if(x*2<=100000 && x*2>=0 && vis[x*2]==0) { //2倍位置的点在范围内且没有走过
            q.push(point(x*2, step+1));
            vis[x*2] = 1;
        }
    }
    printf("%d\n", end_step);
    return 0;
}
