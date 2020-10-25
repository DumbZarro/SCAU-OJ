#include<iostream>
#include<cstdio>
using namespace std;
int n,c[26];
char * ch;
int main(){
    int i,j;
    cin>>n;
    ch=new char[n];
    scanf("%s",ch);
    for(i=0;i<n;i++){
        c[ch[i]-'a']++;
    }
    for(i=0;i<26;i++){
        if(c[i]){
            cout<<(char)('a'+i);
        }
    }
    return 0;
}
