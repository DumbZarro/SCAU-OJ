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
    while(scanf("%d%*c%s%*c%c%*c%d",&tim,nam,&nu,&re)>0){//%*c�����ո�
        //���Ҷ����¼
        i=0;
        while(i<coun&&strcmp(teams[i].name,nam)!=0){
            i++;
        }
        if(i==coun){//��¼�³��ֵĶ���
            strcpy(teams[i].name,nam);
            coun++;
        }
        if(re==0&&teams[i].ac[nu]==0){//ͨ�����ǵ�һ��ͨ��
            teams[i].ac[nu]=1;
            teams[i].time += (tim+teams[i].wa[nu]*20);
            teams[i].accepts++;
        }
        else if(re!=0 && teams[i].ac[nu]==0){//δͨ����֮ǰû��ͨ��
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
//������У������������
//�����ڼ䣬�ύ�����ϵͳ�᷵����ȷ�����Ƚ�������Ļ�ʤ��Ϊ��ȷ�����Ŀ��࣬���ͬ����������ʱ���ٵĶ��顣
//ÿ�������ʱ�仨�ѽ��Ӿ�����ʼ�������ύ���ұ��ж�Ϊ��ȷΪֹ�����ÿһ���ύ���н�����д���Ļ������ӷ�20����ʱ�䣬
//δ��ȷ�������ⲻ��ʱ������Ѿ�������ȷ����Ŀ���ظ��ύ��Ӱ������
//���磺A��B���Ӷ���ȷ���������Ŀ������A���ύ�������ʱ��ֱ��Ǳ�����ʼ��60���Ӻ�165���ӣ�B��Ϊ80���Ӻ�130���ӣ�
//��B�ӵ�һ�����ύ��2�β�ͨ��������A�ӵ�����ʱΪ60+165=225��B��Ϊ��80+20��+130=230������A��������ʱ�ٶ���ʤ��
//���ڸ������л��������ж�����ύʱ��(������)�ͷ��ؽ������Ҫ���������ǰ���������а�
//
//ע��0��Ķ��鲻��Ҫ���
//
//
//
//�����ʽ
//ÿ��һ�����н������ʽΪ��ʱ�䣨�ڼ������ύ�ģ�+��ǿո�+����+��ǿո�+���+��ǿո�+���н����0ͨ��������Ϊ����
//
//����ɴ�дA�ַ���ʼ����2����B���������ƣ���಻����15��
//�������н���Ѿ���ʱ�������
//
//
//�����ʽ
//���������һ��һ������ʽΪ����+��ǿո�+ͨ������+��ǿո�+��ʱ
//
//ע��0��Ķ��鲻��Ҫ���
//���������У�û��ͬ����ͬ��ʱ�����
//
//
//��������
//2 abc A 4
//5 abc B 0
//6 def A 0
//10 abc A 0
//13 xyx A 4
//20 def B 5
//
//
//�������
//abc 2 35
//def 1 6
