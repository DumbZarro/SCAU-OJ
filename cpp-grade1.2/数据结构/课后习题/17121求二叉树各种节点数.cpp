/*
����ֻ��Ҫ�������������ɡ��ڱ����Ĺ����У���������������ans0��ans1��ans2�ֱ��¼����Ϊ0��1��2�Ľ��������Ȼ�������������ۼ��ɡ���ô��ô�����أ�
1.������������Ҳ����������ans0++��
2.������������������������ans2++��
3.else ans1++��
��󰴸�ʽ������ɣ�
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
int ans1=0,ans2=0,ans0=0;
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
        T->data=ch;// ���ɸ����
        CreateBiTree(T->lchild);// ����������
        CreateBiTree(T->rchild);// ����������
    }
    return OK;
}//CreateBiTree
void traverse(BiTree T) {
    if(T) {
        if(!T->lchild&&!T->rchild)
            ans0++;
        else if(T->lchild&&T->rchild)
            ans2++;
        else
            ans1++;
        traverse(T->lchild);
        traverse(T->rchild);
    }
}
int main() { //������
    BiTree T;
    CreateBiTree(T);
    traverse(T);
    cout<<ans2<<'\n';
    cout<<ans1<<'\n';
    cout<<ans0<<'\n';                  //�������
}//main
