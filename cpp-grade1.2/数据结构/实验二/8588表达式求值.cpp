#include<cstdlib>
#include<cstdio>
#include <iostream>
#include <cstring>
#define OK 1
#define ERROR 0
#define STACK_INIT_SIZE 100 // �洢�ռ��ʼ������
#define STACKINCREMENT 10 // �洢�ռ��������

typedef int SElemType; // ����ջԪ������
typedef int Status; // Status�Ǻ���������,��ֵ�Ǻ������״̬���룬��OK��
using namespace  std;
struct SqStack
{
    SElemType *base; // ��ջ����֮ǰ������֮��base��ֵΪNULL
    SElemType *top; // ջ��ָ��
    int stacksize; // ��ǰ�ѷ���Ĵ洢�ռ䣬��Ԫ��Ϊ��λ
}; // ˳��ջ

Status InitStack(SqStack &S)
{
// ����һ����ջS����ջԤ�����СΪSTACK_INIT_SIZE
    S.base=(SElemType*)malloc(STACK_INIT_SIZE*sizeof(SElemType));
    if(!S.base) return ERROR;
    S.top=S.base;
    S.stacksize=STACK_INIT_SIZE;
    return OK;
}

Status Push(SqStack &S,SElemType e)
{
// ��ջS�в���Ԫ��eΪ�µ�ջ��Ԫ��
    if(S.top-S.base>=S.stacksize)
    {
        S.base=(SElemType*)realloc(S.base,(S.stacksize+STACKINCREMENT)*sizeof(SElemType));
        if(!S.base) return ERROR;
        S.top=S.base+S.stacksize;
        S.stacksize+=STACKINCREMENT;
    }
    *S.top++=e;
    return OK;
}

Status Pop(SqStack &S,SElemType &e)
{
// ��ջ���գ���ɾ��S��ջ��Ԫ�أ���e������ֵ��������OK�����򷵻�ERROR
    if(S.top==S.base) return ERROR;
    e=*--S.top;
    return OK;
}

Status GetTop(SqStack S,SElemType &e)
{
// ��ջ���գ�����e����S��ջ��Ԫ�أ�������OK�����򷵻�ERROR
    if(S.top==S.base) return ERROR;
    e=*(S.top-1);
    return OK;
}

int StackLength(SqStack S)
{
// ����ջS��Ԫ�ظ���
    int i;
    i=S.top-S.base;
    return i;
}

Status StackTraverse(SqStack S)
{
// ��ջ����ջ���������ջ�е�ÿ��Ԫ��
    SElemType *p = (SElemType *)malloc(sizeof(SElemType));
    p = S.top;
    if(S.top==S.base)printf("The Stack is Empty!");
    else
    {
        printf("The Stack is: ");
        p--;
        while(p>=S.base)
        {
            printf("%d ", *p);
            p--;
        }
    }
    printf("\n");
    return OK;
}

char prio(char e,char c){//�Ƚ���������ȼ�
    char n;
    switch(c){
        case'+':
        case'-':{
            if(e=='('||e=='=') n='<';  //c>e
            else n='>';}break;
        case'*':
        case'/':{
            if(e=='*'||e=='/'||e==')') n='>';//c<e
            else n='<';}break;
        case'(':{
            if(e==')')
            {
                printf("���Ų�ƥ��\n");
                exit(ERROR);
            }
            else n='<';} //c>e;
            break;
        case')':{
            if(e=='(') n='=';
            else if(e=='=') {printf("ȱ��������\n");exit(ERROR);}
            else n='>';
        }//e>c
            break;
        case'=':{
            if(e=='=') n='=';
            else if(e=='(') {printf("ȱ��������\n");exit(ERROR);}
            else n='>';
        } //e>c
    }//switch

    return n;
}

int main()
{
    SqStack s1,s2;//s1������ջ��s2���ջ
    InitStack(s1);
    InitStack(s2);
    Push(s2,'=');
    char w;
    w=getchar();
        int e;
        GetTop(s2,e);
        while(w!='='||e!='=')
        {
          //  cout<<w<<endl;
          int d=0;
          if(w>='0'&&w<='9') {
              while (w >= '0' && w <= '9') {
                  d = d * 10 + (w - '0');
                  w = getchar();
              }
              Push(s1, d);
             // cout << d << endl;
          }
          else {
              if (prio(e, w) == '<') {
                  //cout<<"123"<<endl;
                  Push(s2, w);
                  //StackTraverse(s1);
                  w = getchar();

              } else if (prio(e, w) == '=' && w == ')') {
                  //cout<<"321"<<endl;
                  int t;
                  Pop(s2, t);
                  w = getchar();
              } else if (prio(e, w) == '>') {
                  int a, b, c = 0, d;
                  Pop(s1, a);
                  Pop(s1, b);
                  Pop(s2, d);
                  if (d == '+')
                      c = a + b;
                  else if (d == '-')
                      c = b - a;
                  else if (d == '/')
                      c = b / a;
                  else if (d == '*')
                      c = b * a;
                  Push(s1, c);
              }
          }
            GetTop(s2,e);
        }
        int r;
        Pop(s1,r);
        cout<<r<<endl;
    return 0;
}
