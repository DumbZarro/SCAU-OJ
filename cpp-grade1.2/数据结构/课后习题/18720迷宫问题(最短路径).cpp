#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
char maze[105][105];//�Թ���
int row,col;//�Թ�����
struct Node{
    int step;
    int row;
    int col;
};
int direction[4][2]={{0,-1},{0,1},{-1,0},{1,0}};//��������

int main(){
    cin>>row>>col;
    for(int i=0;i<row;i++){//���ж�ȡ�Թ�
        scanf("%s",maze[i]);
    }
    Node first;
    first.row=1;
    first.col=1;
    first.step=0;
    queue<Node> qu;//�ڵ����
    qu.push(first);
    while(!qu.empty()){
        Node cur;
        cur=qu.front();
        qu.pop();
        if(cur.row==row&&cur.col==col){
            cout<<cur.step;
            return 0;//�������һ�������Ž�,�õ��Ϳ��Խ���������
        }
        for(int i=0;i<4;i++){
            int new_row = cur.row+direction[i][0];
            int new_col = cur.col+direction[i][1];
            if(new_row<0||new_row>row)continue;
            if(new_col<0||new_col>col)continue;
            if(maze[new_row-1][new_col-1]=='0'){
                Node new_node;
                new_node.row=new_row;
                new_node.col=new_col;
                new_node.step=cur.step+1;
                qu.push(new_node);
                maze[new_row-1][new_col-1]='1';
            }
        }
    }
    cout<<-1;
    return 0;
}
