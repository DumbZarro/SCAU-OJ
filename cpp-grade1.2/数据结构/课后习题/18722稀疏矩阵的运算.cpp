#include <iostream>
#include <algorithm>
using namespace std;
struct node {
    int x,y,s;//xΪ�У�yΪ�У�sΪֵ
    bool operator < (const node &c) const { //���ش�С����Ĺ���
        if(y==c.y)
            return x<c.x;//y��ͬ��xֵС������ǰ��
        else
            return y<c.y;// y��ͬ��yֵС������ǰ��
    }
} nodes[10005];
int main() {
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=0; i<k; i++)
        cin>>nodes[i].x>>nodes[i].y>>nodes[i].s;
    sort(nodes,nodes+k);//�������ع������򣬼�����Ԫ���ɰ�������תΪ�������ȵķ�ʽ�洢
    for(int i=0; i<k; i++)
        cout<<nodes[i].y<<" "<<nodes[i].x<<" "<<nodes[i].s<<endl;//����x��y�����˳��
    return 0;
}
