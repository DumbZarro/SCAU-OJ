#include<iostream>
#include<cstdio>
using namespace std;
void hnt(int n,char A,char B,char C){//A上的N个盘子借助B移动到C
    if(n==1){
        printf("把盘子%d从%c,移动到%c\n",n,A,C);
        return;
    }
    hnt(n-1,A,C,B);//倒数第三个盘子一定是从A移动到B的
    printf("把盘子%d从%c移动到%c\n",n,A,C);//倒数第二个盘子一定是从A移到C的
    hnt(n-1,B,A,C);//最后最小的一个盘子一定是从B移动到C的
}

int main(){
    int i,j,n;
    cin>>n;
    hnt(n,'A','B','C');
    return 0;
}
