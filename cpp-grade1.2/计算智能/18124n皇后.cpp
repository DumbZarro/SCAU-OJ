#include <iostream>
#include <cmath>
using namespace std;
int N;
int res;
int queenPos[100];//�±�����,ֵ����
//���������õĻʺ�λ�á������Ͻ���(0,0)
void NQueen(int k){//ǰk-1�лʺ��Ѿ��ںõ�����£��ڵ�k�м����Ļʺ�
    if(k==N){//k����,N�ǻʺ���,���ʺ��ܰ�����÷�����һ
        res++;
    }//
    for(int i=0;i<N;i++){//ѭ��������
        int j;
        for(j=0;j<k;j++){//ѭ������֮ǰ�ںõĻʺ�
            if(queenPos[j]==i  ||  abs(queenPos[j]-i)==abs(k-j)){
            //if({�ںõĵ�j���ʺ����==��ǰ��}||{�����ʺ�֮��ĸ�==��})
                break;
            }
        }
        if(j==k){//�ж���һ���Ƿ��ܷ�
            queenPos[k]=i;//��¼�ʺ������
            NQueen(k+1);//������һ���ʺ�
        }
    }
}
int main(){
    int c;
    cin>>c;//��ȡcase��
    while(c--){
        cin>>N;//��ȡ�ʺ���
        res=0;
        NQueen(0);//�ӵ�0�п�ʼ�ڻʺ�
        cout<<res<<endl;
    }
    return 0;
}
