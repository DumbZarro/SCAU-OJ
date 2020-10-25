#include <iostream>
#include <cstring>
#include <stack>
using namespace std;
int R,C; //������
int rooms[60][60];
int color[60][60];  // �����Ƿ�Ⱦ��ɫ�ı��
int maxRoomArea = 0, roomNum=0;
int roomArea;
void Dfs(int i,int k){
    if(color[i][k])//�������Ͳ���
        return ;
    roomArea++;//�����µĿո�,�����һ
    color[i][k] = roomNum;//��־�ڼ�������
    //��Ŀ��8421�϶�Ҫ���������������濿
    //1:0001  2:0010  4:0100  8:1000  ����Ϊ0��û�����ǽ
    if((rooms[i][k]&1)==0)Dfs(i,k-1);//������
    if((rooms[i][k]&2)==0)Dfs(i-1,k);// ����
    if((rooms[i][k]&4)==0)Dfs(i,k+1);//����
    if((rooms[i][k]&8)==0)Dfs(i+1,k);//����
}
int main()
{
    cin >> R >> C;//��ȡ����
    for(int i=1;i<=R;++i){
        for(int k=1;k<=C;++k){
            cin >> rooms[i][k];//��ȡ�Ǳ�
        }
    }
    memset(color, 0 ,sizeof(color));//��ʼ��color
    for(int i=1;i<=R;++i){//ѭ������ÿ���ո�
        for(int k=1;k<=C;++k){
            if(!color[i][k]){//����ո�û�б�����
                ++ roomNum;//����һ������
                roomArea = 0;
                Dfs(i,k);//������������������Ĵ�С
                maxRoomArea = max(roomArea,maxRoomArea);//�ҳ����ķ����С
            }
        }
    }
    cout << roomNum <<endl;
    cout << maxRoomArea <<endl;
}
