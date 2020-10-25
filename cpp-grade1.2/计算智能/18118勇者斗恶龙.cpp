#include<iostream>
#include<algorithm>// 因为用到了sort
using namespace std;
int eDragon[200005],warrior[200005];
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int n=1,m=1,i;//判断结束为00,为了防止随机分配到0,设定为1
    while((cin>>n>>m)&&n&&m){//多组数据
        for(i=0;i<n;i++){
            cin>>eDragon[i];
        }
        for(i=0;i<m;i++){
            cin>>warrior[i];
        }
        //排序
        sort(eDragon,eDragon+n);
        sort(warrior,warrior+m);
        int now=0;//要砍的龙的序号
        int cost=0;// 当前总费用
        for(i=0;i<m;i++){//屠龙
            if(warrior[i]>=eDragon[now]){
                cost += warrior[i];//雇佣该骑士
                if(++now==n){
                    break;//如果龙砍完了,退出循环
                }
            }
        }
        if(now<n){//如果龙没砍完
            cout<<"Loowater is doomed!\n";
        }
        else{
            cout<<cost<<endl;
        }
    }
    return 0;
}
