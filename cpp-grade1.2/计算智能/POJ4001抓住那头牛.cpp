#include <iostream>
#include <queue>
#include <cstdio>
using namespace std;

int N, K;//ũ����ʼλ�ڵ�N(0<=N<=100000)��ţλ�ڵ�K(0<=K<=100000)
int vis[201000];//��2x��ѡ��,����Ҫ����2*100000���ϵĴ�С

struct point {
    int pos;
    int step;
    point(int p, int s) { //���캯��....
        pos = p;
        step = s;
    }
};

int main() {
    scanf("%d%d", &N, &K);
    queue<point> q;//��������
    q.push(point(N, 0));//ũ���ʼλ�����
    int end_step = -1;//��ʼ�����ղ���
    while(!q.empty()) {
        point this_pos = q.front();//��ȡ��ͷ
        q.pop();//������ͷ
        int x=this_pos.pos, step=this_pos.step;
        if(x == K) { //�����ǰλ�õ���ţ��λ��
            end_step = step;
            break;
        }
        if(x-1>=0 && x-1<=100000 && vis[x-1]==0) { //���һ���ĵ��ڷ�Χ����û���߹�
            q.push(point(x-1, step+1));
            vis[x-1] = 1;
        }
        if(x+1>=0 && x+1<=100000 && vis[x+1]==0) { //��ǰһ���ĵ��ڷ�Χ����û���߹�
            q.push(point(x+1, step+1));
            vis[x+1] = 1;
        }
        if(x*2<=100000 && x*2>=0 && vis[x*2]==0) { //2��λ�õĵ��ڷ�Χ����û���߹�
            q.push(point(x*2, step+1));
            vis[x*2] = 1;
        }
    }
    printf("%d\n", end_step);
    return 0;
}
