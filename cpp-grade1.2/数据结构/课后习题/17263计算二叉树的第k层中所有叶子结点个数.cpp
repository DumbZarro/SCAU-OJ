/*
�����Ŀ��ֻ��Ҫ��һ��״̬����step����ʾĿǰ���ڵĲ㣬
��step==k��ʱ�����Ǿ��жϴ�ʱ��T�����������������Ƿ�Ϊ�ռ��ɣ�
����Ϊ�գ���ans++���������ans��Ϊ�𰸡�
*/
#include "stdio.h"
#include "malloc.h"
#include<iostream>
using namespace std;
#define TRUE 1
#define FALSE 0
#define OK  1
#define ERROR  0
#define INFEASIBLE -1
#define OVERFLOW -2
typedef int  Status;
typedef char  ElemType;
typedef struct BiTNode {
    ElemType data;
    struct BiTNode *lchild,*rchild;//���Һ���ָ��
} BiTNode,*BiTree;
Status CreateBiTree(BiTree &T) {  // �㷨6.4
    // �������������������н���ֵ��һ���ַ�������#���ַ���ʾ������
    // ������������ʾ�Ķ�����T��
    char ch;
    scanf("%c",&ch);
    if (ch=='#')
        T = NULL;
    else {
        if (!(T = (BiTNode *)malloc(sizeof(BiTNode))))
            return ERROR;
        T->data=ch; // ���ɸ����
        CreateBiTree(T->lchild);   // ����������
        CreateBiTree(T->rchild);  // ����������
    }
    return OK;
} // CreateBiTree
int ans=0,k;
void travel(BiTree T,int step) {
    if(step<k&&T!=NULL) {
        travel(T->lchild,step+1);
        travel(T->rchild,step+1);
    } else if(step==k&&T!=NULL) {
        if((!T->lchild)&&(T->rchild==NULL))
            ans++;
    }
}
int main() { //������
    BiTree T;
    CreateBiTree(T);
    cin>>k;
    travel(T,1);
    cout<<ans<<'\n';                  //�������
}//main
