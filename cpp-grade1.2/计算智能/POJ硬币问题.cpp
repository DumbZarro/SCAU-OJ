#include<iostream>
#include<cstring>
using namespace std;
char Left[3][7];//��ƽ��ߵ�Ӳ��
char Right[3][7];//��ƽ�ұ�
char result[3][7];//���
bool IsFake(char c,bool light);//lightΪ���ʾ�ٱ�Ϊ��

int main(){
    int t;
    cin>>t;
    while(t--){
        for(int i=0;i<3;i++){
            cin>>Left[i]>>Right[i]>>result[i];
            for(char c='A';c<='L';c++){
                if(IsPake(c,true)){
                    cout<<c<<" is the counterfeit coin and it is light.\n";
                    break;
                }
                else if(IsPake(c,false)){
                    cout<<c<<" is the counterfeit coin and it is heavy.\n";
                    break;
                }
            }
        }
    }
    return 0;
}

bool IsFake(char c,bool light){//light Ϊ���ʾ����ٱ�Ϊ�ᣬ�����ʾ����ٱ�Ϊ��
    for(int i=0;i<3;++i){
        char *pLeft,*pRight; //ָ����ƽ���ߵ��ַ���
        if(light) {
            pLeft = Left[i]; pRight = Right[i];
        }
        else {
            pLeft = Right[i]; pRight = Left[i];
        }
        switch(result[i][0]){
            case 'u':
                    if(strchr(pRight.c)==NULL){
                        return false;
                    }break;
            case 'e':
                    if(strchr(pRight.c)||strchr(pLeft.c)){
                        return false;
                    }break;
            case 'd':
                    if(strchr(pLeft.c)==NULL){
                        return false;
                    }break;
        }
    }
    return true;
}

