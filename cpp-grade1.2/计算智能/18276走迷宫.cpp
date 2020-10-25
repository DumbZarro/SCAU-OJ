#include<iostream>
#include<algorithm>
#include<queue>//队列的头文件
#include<cstdio>//scanf、printf
using namespace std;
char d[105][105];//迷宫体，1为墙、0为可通过
int por[105][4];//传送门数组，一个传送门由传送起点的行、列和传送终点的行、列
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
        for(int i=0;i<r;i++){
            scanf("%s",d[i]);//因为是字符型，所以每行可以直接以字符串形式输入
        }
        int portal;//定义传送门数量
        cin>>portal;
        for(int i=0;i<portal;i++){//循环读取传送门
            scanf("%d%d%d%d",&por[i][0],&por[i][1],&por[i][2],&por[i][3]);
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
            int jump=0;//标志是否进入传送门
            cur=qu.front();//读取队头节点
            qu.pop();//弹出推头节点
            if(cur.row==dr&&cur.col==dc){//标志是否到达终点
                printf("%d\n",cur.step);
                flag=1;//标记到达终点
            }
            for(int i=0;i<portal;i++){//判断本局是否有传送门,有多个的话需要循环对比
                if(cur.row==por[i][0]&&cur.col==por[i][1]){//该点是传送门
                    LOC newcur;//创建传送门出口节点并赋值
                    newcur.row=por[i][2];
                    newcur.col=por[i][3];
                    newcur.step=cur.step+1;//步数加1
                    qu.push(newcur);//入队
                    jump=1;//标记，待下次出队时再进行上下左右操作
                    d[por[i][2]][por[i][3]]='1';//将该位置置'1'，走过的不能再走
                }
            }
            if(!jump){//不是传送门
                for(int i=0;i<4;i++){//对玩家进行上下左右操作
                    int new_r=cur.row+dir[i][0];
                    int new_c=cur.col+dir[i][1];
                    if(new_r>=r||new_r<0)continue;//走出迷宫范围，无效操作，进行其他方向的操作
                    if(new_c>=c||new_c<0)continue;
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
        }
        if(!flag){//规定步数内找不到终点
            cout<<"die"<<endl;
        }
    }
    return 0;
}

