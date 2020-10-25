#include<iostream>
using namespace std;
/*
    用函数实现如下二叉排序树算法：
    (1) 插入新结点
    (2) 前序、中序、后序遍历二叉树
    (3) 中序遍历的非递归算法 -> 用到栈
    (4) 层次遍历二叉树  ->  用到队列
    (5) 在二叉树中查找给定关键字(函数返回值为成功1,失败0)
*/
int a[200];
typedef struct node { //二叉排序树结构体
    int data;
    struct node *lchild,*rchild;
} node,*bst;//bst是二叉树结构体指针

typedef struct { //队列结构体
    bst *base;//定义一个base数组,数组的元素都是二叉树结构体指针
    int head;
    int tail;
} b_queue;

typedef struct { //栈结构体
    bst *base;//定义一个base数组,数组的元素都是二叉树结构体指针
    bst *top;
    int stacksize;
} b_stack;


int initialstack(b_stack &s) {
    s.base=new bst[200];
    if(s.base==NULL)
        return 0;
    s.stacksize=200;
    s.top=s.base;
    return 1;
}

int push(b_stack &s,bst e) {
    if(s.top-s.base==s.stacksize)
        return 0;
    *s.top=e;
    s.top++;
    return 1;
}

int pop(b_stack &s,bst &e) {
    if(s.top==s.base)
        return 0;
    s.top--;
    e=*s.top;
    return 1;
}

int initialqueue(b_queue &q) { //队列初始化
    q.base=new bst[200];
    if(q.base==NULL)
        return 0;
    q.head=q.tail=0;
    return 1;
}

int in(b_queue &q,bst e) { //队列入队
    if((q.tail+1)%200==q.head)
        return 0;
    q.base[q.tail]=e;
    q.tail=(q.tail+1)%200;
    return 1;
}

int out(b_queue &q,bst &e) { //队列出队
    if(q.head==q.tail)
        return 0;
    e=q.base[q.head];
    q.head=(q.head+1)%200;
    return 1;
}

void ins(bst &t,int n) { //二叉排序树插入
    if(t==NULL) {
        t=new node;
        t->data=n;
        t->lchild=t->rchild=NULL;//cout<<t->data;
        return ;
    }
    else if(n < t->data)
        return ins(t->lchild,n);
    else if(n > t->data)
        return ins(t->rchild,n);

}

void prego(bst t) { //先序遍历
    if(t) {
        cout<<t->data<<" ";
        prego(t->lchild);
        prego(t->rchild);
    }
}
void midgo(bst t) { //中序遍历
    if(t) {
        midgo(t->lchild);
        cout<<t->data<<" ";
        midgo(t->rchild);
    }
}
void reargo(bst t) { //后序遍历
    if(t) {
        reargo(t->lchild);
        reargo(t->rchild);
        cout<<t->data<<" ";
    }
}
int search(bst t,int n) {//利用二叉排序树二分查找
    if(t==NULL)
        return 0;
    else {
        if(n==t->data)
            return 1;
        else if(n > t->data)
            return search(t->rchild,n);
        else if(n < t->data)
            return search(t->lchild,n);
    }
}

void levelgo(bst t,b_queue &q) {//层次遍历,队列
    in(q,t);
    while(q.head!=q.tail) {
        bst e;
        out(q,e);
        cout<<e->data<<" ";
        if(e->lchild!=NULL)
            in(q,e->lchild);
        if(e->rchild!=NULL)
            in(q,e->rchild);
    }
    cout<<endl;
}

void norecurmid(bst t,b_stack &s) { //非递归中序遍历,栈
    while(t!=NULL||s.base!=s.top) { //只有遍历完并且栈空了才结束，单独一个栈为空是不够的，
            //因为一开始就是空栈，单独一个t为NULL也是不够的，因为这只代表你遍历完一条分支，此时栈是非空的
        if(t) {
            push(s,t);
            t=t->lchild;
        } else {
            pop(s,t);
            cout<< t->data <<" ";
            t=t->rchild;
        }
    }
    cout<<endl;
}

int main() {
    bst t=NULL;
    int n;
    cin>>n;
    for(int i=0; i<n; i++) {
        cin>>a[i];
        ins(t,a[i]);
    }
    prego(t);
    cout<<endl;
    midgo(t);
    cout<<endl;
    reargo(t);
    cout<<endl;

    int m;
    cin>>m;
    cout<<search(t,m)<<endl;
    cin>>m;
    cout<<search(t,m)<<endl;

    int cha;
    cin>>cha;
    ins(t,cha);
    prego(t);
    cout<<endl;
    midgo(t);
    cout<<endl;
    reargo(t);
    cout<<endl;

    b_stack s;
    initialstack(s);
    norecurmid(t,s);

    b_queue q;
    initialqueue(q);
    levelgo(t,q);

    return 0;
}

