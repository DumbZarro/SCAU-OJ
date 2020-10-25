/*
这题只需要遍历二叉树即可。在遍历的过程中，我们用三个变量ans0，ans1，ans2分别记录出度为0，1，2的结点数量。然后分三种情况讨论即可。那么怎么讨论呢？
1.既无左子树，也无右子树，ans0++；
2.既有左子树，又有右子树，ans2++；
3.else ans1++；
最后按格式输出即可；
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
        T->data=ch;// 生成根结点
        CreateBiTree(T->lchild);// 构造左子树
        CreateBiTree(T->rchild);// 构造右子树
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
int main() { //主函数
    BiTree T;
    CreateBiTree(T);
    traverse(T);
    cout<<ans2<<'\n';
    cout<<ans1<<'\n';
    cout<<ans0<<'\n';                  //补充代码
}//main
