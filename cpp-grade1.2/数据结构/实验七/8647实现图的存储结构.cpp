#include<iostream>
#include<cstdio>
using namespace std;
#define MVNum 100 //最大顶点数
typedef int ArcType;//边的权值类型
typedef struct {
    ArcType arcs[MVNum][MVNum];//邻接矩阵
    int vexnum,arcnum;//点数和边数
} AMGraph;

void CreateUDN(AMGraph &G) {
    //采用邻接矩阵表示法，创建有向网G
    cin>>G.vexnum>>G.arcnum;
    for(int i=0; i<G.vexnum; i++) {
        for(int j=0; j<G.vexnum; j++) { //初始化邻接矩阵，初始值设为0
            G.arcs[i][j]=0;
        }
    }
    for(int k=0; k<G.arcnum; k++) {
        //构造邻接矩阵

        int v1,v2;
        cin>>v1>>v2;//输入一条边依附的顶点
        int i=v1-1,j=v2-1;//确定v1，v2在G中的位置，即顶点数组的下标
        G.arcs[i][j]=1;//边<v1,v2>的权值改为1；
    }
    for(int i=0; i<G.vexnum; i++) { //打印

        for(int j=0; j<G.vexnum; j++)
            printf("%d ",G.arcs[i][j]);
        printf("\n");
    }
}

int main() {
    AMGraph G;
    CreateUDN(G);
    return 0;
}
