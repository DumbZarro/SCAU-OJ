#include <iostream>
#include <cstdio>
#include <cstring>
typedef long long ll;
using namespace std;
int st[105],top=0;//���ŵ�ջ
char ch[105];
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int i,j;
    while(scanf("%s",ch)!=EOF){//һֱ����ֱ������
        for(i=0; i<strlen(ch); i++){
            if(ch[i]=='('){//����ַ�Ϊ(�ͱ��Ϊ�ո�
                st[top++]=i,ch[i]=' ';
            }
            else if(ch[i]==')'){
                if(top==0){//����ĵط����Ϊ?
                    ch[i]='?';
                }
                else{
                    top--;
                    ch[i]=' ';//��ǰ����ƥ������žͱ��Ϊ�ո�
                }
            }
            else{
                ch[i]=' ';
            }
        }
        while(top){
            ch[st[--top]]='$';
        }
        printf("%s\n",ch);
    }
    return 0;
}
