#include<iostream>
#include<string>
using namespace std;
string s;

int main(){
	int i,j,t,n,c2,c3,c4;
	cini>>t;
	while(t--){
		cin>>s;
		for(i=0;i<s.size();i++){
			if(s[i]==s[i+1]){
				if(s[i+1]==s[i+2]==s[i+3]){
					s.erase(i+2,1);
					i--;
				}
			}
		}
		cout<<s<<endl;
	}
	return 0;
}
