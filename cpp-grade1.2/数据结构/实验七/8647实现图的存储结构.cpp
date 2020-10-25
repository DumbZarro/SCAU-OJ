#include<iostream>
#include<cstdio>
using namespace std;
#define MVNum 100 //��󶥵���
typedef int ArcType;//�ߵ�Ȩֵ����
typedef struct {
    ArcType arcs[MVNum][MVNum];//�ڽӾ���
    int vexnum,arcnum;//�����ͱ���
} AMGraph;

void CreateUDN(AMGraph &G) {
    //�����ڽӾ����ʾ��������������G
    cin>>G.vexnum>>G.arcnum;
    for(int i=0; i<G.vexnum; i++) {
        for(int j=0; j<G.vexnum; j++) { //��ʼ���ڽӾ��󣬳�ʼֵ��Ϊ0
            G.arcs[i][j]=0;
        }
    }
    for(int k=0; k<G.arcnum; k++) {
        //�����ڽӾ���

        int v1,v2;
        cin>>v1>>v2;//����һ���������Ķ���
        int i=v1-1,j=v2-1;//ȷ��v1��v2��G�е�λ�ã�������������±�
        G.arcs[i][j]=1;//��<v1,v2>��Ȩֵ��Ϊ1��
    }
    for(int i=0; i<G.vexnum; i++) { //��ӡ

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
