#include <iostream>
#include <cstdio>
#include <cstring>
typedef long long ll;
using namespace std;
int st[105],top=0;//括号的栈
char ch[105];
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int i,j;
    while(scanf("%s",ch)!=EOF){//一直输入直到结束
        for(i=0; i<strlen(ch); i++){
            if(ch[i]=='('){//如果字符为(就标记为空格
                st[top++]=i,ch[i]=' ';
            }
            else if(ch[i]==')'){
                if(top==0){//错误的地方标记为?
                    ch[i]='?';
                }
                else{
                    top--;
                    ch[i]=' ';//若前面有匹配的括号就标记为空格
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
