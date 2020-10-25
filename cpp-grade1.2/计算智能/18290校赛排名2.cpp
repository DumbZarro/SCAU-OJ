#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
typedef struct{
    int time;
    char name[100];
    char ac[256];
    int wa[256];
    int accepts;
} SCORE;
SCORE teams[100000]={{0}};

bool cmp(SCORE a,SCORE b){
    if(a.accepts!=b.accepts){
        return a.accepts>b.accepts;
    }
    else if(a.time!=b.time){
        return a.time<b.time;
    }
    else{
        return 1;
    }
}

int main(){
    char nam[100],nu;
    int re,tim,i=0,coun=0;
    while(scanf("%d%*c%s%*c%c%*c%d",&tim,nam,&nu,&re)>0){//%*c丢弃空格
        //查找队伍记录
        i=0;
        while(i<coun&&strcmp(teams[i].name,nam)!=0){
            i++;
        }
        if(i==coun){//记录新出现的队名
            strcpy(teams[i].name,nam);
            coun++;
        }
        if(re==0&&teams[i].ac[nu]==0){//通过且是第一次通过
            teams[i].ac[nu]=1;
            teams[i].time += (tim+teams[i].wa[nu]*20);
            teams[i].accepts++;
        }
        else if(re!=0 && teams[i].ac[nu]==0){//未通过且之前没有通过
            teams[i].wa[nu]++;
        }
    }
    stable_sort(teams,teams+coun,cmp);
    for(int j=0;j<coun;j++){
        if(teams[j].accepts!=0){
            printf("%s %d %d\n",teams[j].name,teams[j].accepts,teams[j].time);
        }
    }
    return 0;
}
//下面是校赛的排名规则：
//比赛期间，提交代码后，系统会返回正确或错误等结果。最后的获胜者为正确解答题目最多，如果同题数则总用时最少的队伍。
//每道试题的时间花费将从竞赛开始到试题提交并且被判定为正确为止，其间每一次提交运行结果被判错误的话将被加罚20分钟时间，
//未正确解答的试题不记时，如果已经返回正确的题目再重复提交则不影响结果。
//例如：A、B两队都正确完成两道题目，其中A队提交这两题的时间分别是比赛开始后60分钟和165分钟，B队为80分钟和130分钟，
//但B队第一个题提交了2次才通过。这样A队的总用时为60+165=225而B队为（80+20）+130=230，所以A队以总用时少而获胜。
//现在给出裁判机上面所有队伍的提交时间(分钟数)和返回结果，需要你编程输出当前比赛的排行榜。
//
//注：0题的队伍不需要输出
//
//
//
//输入格式
//每行一个评判结果，格式为：时间（第几分钟提交的）+半角空格+队名+半角空格+题号+半角空格+评判结果（0通过，其它为出错）
//
//题号由大写A字符开始，第2题是B，依次类推，最多不超过15题
//所有评判结果已经按时间排序好
//
//
//输出格式
//输出排名，一行一个，格式为队名+半角空格+通过题数+半角空格+罚时
//
//注：0题的队伍不需要输出
//测试数据中，没有同题且同罚时的情况
//
//
//输入样例
//2 abc A 4
//5 abc B 0
//6 def A 0
//10 abc A 0
//13 xyx A 4
//20 def B 5
//
//
//输出样例
//abc 2 35
//def 1 6
