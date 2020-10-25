#include<iostream>
#include<algorithm>
#include<queue>//���е�ͷ�ļ�
#include<cstdio>//scanf��printf
using namespace std;
char d[105][105];//�Թ��壬1Ϊǽ��0Ϊ��ͨ��
int por[105][4];//���������飬һ���������ɴ��������С��кʹ����յ���С���
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
        for(int i=0;i<r;i++){
            scanf("%s",d[i]);//��Ϊ���ַ��ͣ�����ÿ�п���ֱ�����ַ�����ʽ����
        }
        int portal;//���崫��������
        cin>>portal;
        for(int i=0;i<portal;i++){//ѭ����ȡ������
            scanf("%d%d%d%d",&por[i][0],&por[i][1],&por[i][2],&por[i][3]);
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
            int jump=0;//��־�Ƿ���봫����
            cur=qu.front();//��ȡ��ͷ�ڵ�
            qu.pop();//������ͷ�ڵ�
            if(cur.row==dr&&cur.col==dc){//��־�Ƿ񵽴��յ�
                printf("%d\n",cur.step);
                flag=1;//��ǵ����յ�
            }
            for(int i=0;i<portal;i++){//�жϱ����Ƿ��д�����,�ж���Ļ���Ҫѭ���Ա�
                if(cur.row==por[i][0]&&cur.col==por[i][1]){//�õ��Ǵ�����
                    LOC newcur;//���������ų��ڽڵ㲢��ֵ
                    newcur.row=por[i][2];
                    newcur.col=por[i][3];
                    newcur.step=cur.step+1;//������1
                    qu.push(newcur);//���
                    jump=1;//��ǣ����´γ���ʱ�ٽ����������Ҳ���
                    d[por[i][2]][por[i][3]]='1';//����λ����'1'���߹��Ĳ�������
                }
            }
            if(!jump){//���Ǵ�����
                for(int i=0;i<4;i++){//����ҽ����������Ҳ���
                    int new_r=cur.row+dir[i][0];
                    int new_c=cur.col+dir[i][1];
                    if(new_r>=r||new_r<0)continue;//�߳��Թ���Χ����Ч������������������Ĳ���
                    if(new_c>=c||new_c<0)continue;
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
        }
        if(!flag){//�涨�������Ҳ����յ�
            cout<<"die"<<endl;
        }
    }
    return 0;
}

