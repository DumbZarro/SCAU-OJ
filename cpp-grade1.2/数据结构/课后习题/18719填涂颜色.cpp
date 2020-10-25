#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int map[35][35],book[35][35],vis[35][35];//vis用来标记该点的类型,book用来标记是否走过
int ok,n;//ok为标记值
int nx[4]= {0,0,1,-1},ny[4]= {1,-1,0,0};//位移数组
void dfs(int x,int y) {//深度优先
    if(x<1||y<1||x>n||y>n) {//如果点在边边,不是封闭圈,标记值为1
        ok=1;//这里反人类的让ok=1是因为全局数组默认初始化为0
        return ;
    }
    if(map[x][y]||book[x][y]) {//遇到墙了,或者,这里走过了,就不走了
        return ;
    }
    book[x][y]=1;//标记走过
    for(int i=0; i<4; i++) {
        dfs(x+nx[i],y+ny[i]);//四个方向走
    }
}
int main() {
    scanf("%d",&n);
    for(int i=1; i<=n; i++) {//读取图
        for(int j=1; j<=n; j++) {
            scanf("%d",&map[i][j]);
        }
    }
    for(int i=1; i<=n; i++) {//处理图
        for(int j=1; j<=n; j++) {
            if(!map[i][j]&&!vis[i][j]) {
                memset(book,0,sizeof(book));//初始化,全部地方没有走过
                ok=2;//假设选的点属于封闭圈
                dfs(i,j);
                for(int a=1; a<=n; a++) {
                    for(int b=1; b<=n; b++) {
                        if(book[a][b]) {//如果走过
                            vis[a][b]=ok;//标记
                        }
                    }
                }
            }
        }
    }
    for(int i=1; i<=n; i++) {//输出图
        for(int j=1; j<=n; j++) {
            if(vis[i][j]==1) {
                printf("0 ");
            } else if(vis[i][j]==0) {
                printf("1 ");
            } else if(vis[i][j]==2) {
                printf("2 ");
            }
        }
        printf("\n");
    }
    return 0;
}

