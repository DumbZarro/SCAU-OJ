#include<iostream>
#include<malloc.h>
#include<stack>
#include<queue>
#include<algorithm>
using namespace std;

typedef struct tree {
    int data;
    struct tree *lchild,*rchild;
} node,*bst;

void grow(bst &t,int data) { //二叉树生成/插入
    if(t==NULL) {
        t= new node;
        t->data=data;
        t->lchild=t->rchild=NULL;
    } else if(data >= t->data)
        grow(t->rchild,data);
    else if(data < t->data)
        grow(t->lchild,data);
}

void pre_go(bst t) {//先序遍历
    if(t) {
        cout<<t->data<<" ";
        pre_go(t->lchild);
        pre_go(t->rchild);
    }
}

void mid_go(bst t) {//中序遍历
    if(t) {
        mid_go(t->lchild);
        cout<<t->data<<" ";
        mid_go(t->rchild);
    }

}
void rear_go(bst t) {//后序遍历
    if(t) {
        rear_go(t->lchild);
        rear_go(t->rchild);
        cout<<t->data<<" ";
    }

}

void search_node(bst t,int num) {//查找
    if(t==NULL)
        cout<<"0"<<endl;//这个条件必须写最前面
    else if(t->data==num)
        cout<<"1"<<endl;
    else if(t->data<num)
        search_node(t->rchild,num);
    else if(t->data>num)
        search_node(t->lchild,num);

}

void none_recursive_mid(bst t,stack<bst> &s) { //非递归中序遍历
    while(!s.empty()||t) {
        if(t) {
            s.push(t);
            t=t->lchild;
        } else {
            t=s.top();//返回栈顶元素
            cout<<t->data<<" ";
            s.pop();//弹出栈顶元素
            t=t->rchild;
        }
    }
    cout<<endl;
}

void level_go(bst t,queue<bst> q) {//层次遍历
    q.push(t);
    while(!q.empty()) {
        t=q.front();
        q.pop();
        cout<<t->data<<" ";
        if(t->lchild)
            q.push(t->lchild);
        if(t->rchild)
            q.push(t->rchild);
    }
    cout<<endl;
}

void change(bst &t) {//递归交换二叉树左右节点
    if(!t)
        return ;
    swap(t->lchild,t->rchild);
    change(t->lchild);
    change(t->rchild);
}

int tree_depth(bst t) {//递归算二叉树深度
    if(!t)
        return 0;
    return max(tree_depth(t->lchild),tree_depth(t->rchild))+1;
}

int leaf_node(bst t) {//求叶子总数
    if(!t)
        return 0;
    if(!t->lchild&&!t->rchild)
        return 1;
    return leaf_node(t->lchild)+leaf_node(t->rchild);
}
int main() {
    bst T=NULL;
    //创建树
    int m,data;
    cin>>m;
    for(int i=0; i<=m-1; i++) {
        cin>>data;
        grow(T,data);
    }
    //先中后序打印
    pre_go(T);
    cout<<endl;
    mid_go(T);
    cout<<endl;
    rear_go(T);
    cout<<endl;
    //查找
    int num;
    cin>>num;
    search_node(T,num);
    cin>>num;
    search_node(T,num);
    //插入
    cin>>data;
    grow(T,data);
    //先中后序打印
    pre_go(T);
    cout<<endl;
    mid_go(T);
    cout<<endl;
    rear_go(T);
    cout<<endl;
    //非递归中序遍历
    stack<bst> s;
    none_recursive_mid(T,s);
    //层次遍历
    queue<bst> q;
    level_go(T,q);
    //交换子树
    change(T);
    //先中后序打印
    pre_go(T);
    cout<<endl;
    mid_go(T);
    cout<<endl;
    rear_go(T);
    cout<<endl;
    //交换子树
    change(T);
    //先中后序打印
    pre_go(T);
    cout<<endl;
    mid_go(T);
    cout<<endl;
    rear_go(T);
    cout<<endl;
    //树的深度
    cout<<tree_depth(T)<<endl;
    //叶子结点总数
    cout<<leaf_node(T)<<endl;
    return 0;
}

