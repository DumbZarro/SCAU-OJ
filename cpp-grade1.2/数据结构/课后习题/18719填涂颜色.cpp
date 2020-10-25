#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int map[35][35],book[35][35],vis[35][35];//vis������Ǹõ������,book��������Ƿ��߹�
int ok,n;//okΪ���ֵ
int nx[4]= {0,0,1,-1},ny[4]= {1,-1,0,0};//λ������
void dfs(int x,int y) {//�������
    if(x<1||y<1||x>n||y>n) {//������ڱ߱�,���Ƿ��Ȧ,���ֵΪ1
        ok=1;//���ﷴ�������ok=1����Ϊȫ������Ĭ�ϳ�ʼ��Ϊ0
        return ;
    }
    if(map[x][y]||book[x][y]) {//����ǽ��,����,�����߹���,�Ͳ�����
        return ;
    }
    book[x][y]=1;//����߹�
    for(int i=0; i<4; i++) {
        dfs(x+nx[i],y+ny[i]);//�ĸ�������
    }
}
int main() {
    scanf("%d",&n);
    for(int i=1; i<=n; i++) {//��ȡͼ
        for(int j=1; j<=n; j++) {
            scanf("%d",&map[i][j]);
        }
    }
    for(int i=1; i<=n; i++) {//����ͼ
        for(int j=1; j<=n; j++) {
            if(!map[i][j]&&!vis[i][j]) {
                memset(book,0,sizeof(book));//��ʼ��,ȫ���ط�û���߹�
                ok=2;//����ѡ�ĵ����ڷ��Ȧ
                dfs(i,j);
                for(int a=1; a<=n; a++) {
                    for(int b=1; b<=n; b++) {
                        if(book[a][b]) {//����߹�
                            vis[a][b]=ok;//���
                        }
                    }
                }
            }
        }
    }
    for(int i=1; i<=n; i++) {//���ͼ
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

