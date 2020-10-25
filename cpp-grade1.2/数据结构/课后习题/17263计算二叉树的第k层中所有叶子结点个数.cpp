/*
这道题目，只需要用一个状态变量step来表示目前所在的层，
当step==k的时候，我们就判断此时的T的左子树和右子树是否为空即可，
若都为空，则ans++；最后所得ans即为答案。
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
    struct BiTNode *lchild,*rchild;//左右孩子指针
} BiTNode,*BiTree;
Status CreateBiTree(BiTree &T) {  // 算法6.4
    // 按先序次序输入二叉树中结点的值（一个字符），’#’字符表示空树，
    // 构造二叉链表表示的二叉树T。
    char ch;
    scanf("%c",&ch);
    if (ch=='#')
        T = NULL;
    else {
        if (!(T = (BiTNode *)malloc(sizeof(BiTNode))))
            return ERROR;
        T->data=ch; // 生成根结点
        CreateBiTree(T->lchild);   // 构造左子树
        CreateBiTree(T->rchild);  // 构造右子树
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
int main() { //主函数
    BiTree T;
    CreateBiTree(T);
    cin>>k;
    travel(T,1);
    cout<<ans<<'\n';                  //补充代码
}//main
