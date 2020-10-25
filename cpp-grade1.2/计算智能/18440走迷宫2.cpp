#include<iostream>
#include<algorithm>
#include<queue>//队列的头文件
#include<cstdio>//scanf、printf
using namespace std;
char d[105][105];//迷宫体，1为墙、0为可通过
int sr,sc,dr,dc,r,c;//sr、sc为起点行列，dr、dc为终点行列，r、c为迷宫体的行列大小
int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};//以一个二维数组定义4个方向
typedef struct{//注意这个typedef
    int step;
    int row;
    int col;
}LOC;//定义一个结构体，包含该点所在行、列和已经走的步数

int main(){
    int n;
    cin>>n;
    while(n--){//多case
        cin>>r>>c;//读取迷宫行列
        int flag=0;//到达终点的标志
        for(int i=0;i<r;i++){//读取迷宫
            scanf("%s",d[i]);//因为是字符型，所以每行可以直接以字符串形式输入
        }
        cin>>sr>>sc>>dr>>dc;//读取起点和终点
        //定义一个初始结构体
        LOC first;
        first.row=sr;
        first.col=sc;
        first.step=0;
        queue <LOC>qu;
        qu.push(first);//入队
        while(!qu.empty()){//队列不空则继续循环
            LOC cur;
            cur=qu.front();//读取队头节点
            qu.pop();//弹出队头节点
            if(cur.row==dr&&cur.col==dc){//标志是否到达终点
                printf("%d\n",cur.step);
                flag=1;//标记到达终点
            }
            for(int i=0;i<4;i++){//对玩家进行上下左右操作
                int new_r=cur.row+dir[i][0];
                int new_c=cur.col+dir[i][1];

                if(new_r>=r)new_r=0;//玩家走到了最下边后再往下，即到达最上边
                if(new_r<0)new_r=r-1;//玩家走到了最上边后再往上，即到达最下边
                if(new_c>=c)new_c=0;//玩家走到了最左边后再往左，即到达最右边
                if(new_c<0)new_c=c-1;//玩家走到了最右边后再往右，即到达最左边

                if(d[new_r][new_c]=='0'){//如果该点不是墙且还未走过该点，则有效
                    LOC newcur;//创建新节点并赋值
                    newcur.row=new_r;
                    newcur.col=new_c;
                    newcur.step=cur.step+1;
                    qu.push(newcur);//该操作有效，入队
                    d[new_r][new_c]='1';//设置为走过
                }
            }
        }
        if(!flag){//规定步数内找不到终点
            cout<<"die"<<endl;
        }
    }
    return 0;
}

