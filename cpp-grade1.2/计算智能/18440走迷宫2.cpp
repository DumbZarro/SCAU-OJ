#include<iostream>
#include<algorithm>
#include<queue>//���е�ͷ�ļ�
#include<cstdio>//scanf��printf
using namespace std;
char d[105][105];//�Թ��壬1Ϊǽ��0Ϊ��ͨ��
int sr,sc,dr,dc,r,c;//sr��scΪ������У�dr��dcΪ�յ����У�r��cΪ�Թ�������д�С
int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};//��һ����ά���鶨��4������
typedef struct{//ע�����typedef
    int step;
    int row;
    int col;
}LOC;//����һ���ṹ�壬�����õ������С��к��Ѿ��ߵĲ���

int main(){
    int n;
    cin>>n;
    while(n--){//��case
        cin>>r>>c;//��ȡ�Թ�����
        int flag=0;//�����յ�ı�־
        for(int i=0;i<r;i++){//��ȡ�Թ�
            scanf("%s",d[i]);//��Ϊ���ַ��ͣ�����ÿ�п���ֱ�����ַ�����ʽ����
        }
        cin>>sr>>sc>>dr>>dc;//��ȡ�����յ�
        //����һ����ʼ�ṹ��
        LOC first;
        first.row=sr;
        first.col=sc;
        first.step=0;
        queue <LOC>qu;
        qu.push(first);//���
        while(!qu.empty()){//���в��������ѭ��
            LOC cur;
            cur=qu.front();//��ȡ��ͷ�ڵ�
            qu.pop();//������ͷ�ڵ�
            if(cur.row==dr&&cur.col==dc){//��־�Ƿ񵽴��յ�
                printf("%d\n",cur.step);
                flag=1;//��ǵ����յ�
            }
            for(int i=0;i<4;i++){//����ҽ����������Ҳ���
                int new_r=cur.row+dir[i][0];
                int new_c=cur.col+dir[i][1];

                if(new_r>=r)new_r=0;//����ߵ������±ߺ������£����������ϱ�
                if(new_r<0)new_r=r-1;//����ߵ������ϱߺ������ϣ����������±�
                if(new_c>=c)new_c=0;//����ߵ�������ߺ������󣬼��������ұ�
                if(new_c<0)new_c=c-1;//����ߵ������ұߺ������ң������������

                if(d[new_r][new_c]=='0'){//����õ㲻��ǽ�һ�δ�߹��õ㣬����Ч
                    LOC newcur;//�����½ڵ㲢��ֵ
                    newcur.row=new_r;
                    newcur.col=new_c;
                    newcur.step=cur.step+1;
                    qu.push(newcur);//�ò�����Ч�����
                    d[new_r][new_c]='1';//����Ϊ�߹�
                }
            }
        }
        if(!flag){//�涨�������Ҳ����յ�
            cout<<"die"<<endl;
        }
    }
    return 0;
}

