#include <iostream>
#include <cstring>
#include <stack>
using namespace std;
int R,C; //行列数
int rooms[60][60];
int color[60][60];  // 方块是否染过色的标记
int maxRoomArea = 0, roomNum=0;
int roomArea;
void Dfs(int i,int k){
    if(color[i][k])//如果算过就不算
        return ;
    roomArea++;//发现新的空格,面积加一
    color[i][k] = roomNum;//标志第几个房间
    //题目给8421肯定要往二进制运算上面靠
    //1:0001  2:0010  4:0100  8:1000  相与为0则没有这个墙
    if((rooms[i][k]&1)==0)Dfs(i,k-1);//向西走
    if((rooms[i][k]&2)==0)Dfs(i-1,k);// 向北走
    if((rooms[i][k]&4)==0)Dfs(i,k+1);//向西
    if((rooms[i][k]&8)==0)Dfs(i+1,k);//向南
}
int main()
{
    cin >> R >> C;//读取行列
    for(int i=1;i<=R;++i){
        for(int k=1;k<=C;++k){
            cin >> rooms[i][k];//读取城堡
        }
    }
    memset(color, 0 ,sizeof(color));//初始化color
    for(int i=1;i<=R;++i){//循环遍历每个空格
        for(int k=1;k<=C;++k){
            if(!color[i][k]){//如果空格没有被看过
                ++ roomNum;//开启一个房间
                roomArea = 0;
                Dfs(i,k);//深度优先算出整个房间的大小
                maxRoomArea = max(roomArea,maxRoomArea);//找出最大的房间大小
            }
        }
    }
    cout << roomNum <<endl;
    cout << maxRoomArea <<endl;
}
