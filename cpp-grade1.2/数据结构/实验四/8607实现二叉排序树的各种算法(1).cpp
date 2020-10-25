#include<iostream>
using namespace std;
/*
    �ú���ʵ�����¶����������㷨��
    (1) �����½��
    (2) ǰ�����򡢺������������
    (3) ��������ķǵݹ��㷨 -> �õ�ջ
    (4) ��α���������  ->  �õ�����
    (5) �ڶ������в��Ҹ����ؼ���(��������ֵΪ�ɹ�1,ʧ��0)
*/
int a[200];
typedef struct node { //�����������ṹ��
    int data;
    struct node *lchild,*rchild;
} node,*bst;//bst�Ƕ������ṹ��ָ��

typedef struct { //���нṹ��
    bst *base;//����һ��base����,�����Ԫ�ض��Ƕ������ṹ��ָ��
    int head;
    int tail;
} b_queue;

typedef struct { //ջ�ṹ��
    bst *base;//����һ��base����,�����Ԫ�ض��Ƕ������ṹ��ָ��
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

int initialqueue(b_queue &q) { //���г�ʼ��
    q.base=new bst[200];
    if(q.base==NULL)
        return 0;
    q.head=q.tail=0;
    return 1;
}

int in(b_queue &q,bst e) { //�������
    if((q.tail+1)%200==q.head)
        return 0;
    q.base[q.tail]=e;
    q.tail=(q.tail+1)%200;
    return 1;
}

int out(b_queue &q,bst &e) { //���г���
    if(q.head==q.tail)
        return 0;
    e=q.base[q.head];
    q.head=(q.head+1)%200;
    return 1;
}

void ins(bst &t,int n) { //��������������
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

void prego(bst t) { //�������
    if(t) {
        cout<<t->data<<" ";
        prego(t->lchild);
        prego(t->rchild);
    }
}
void midgo(bst t) { //�������
    if(t) {
        midgo(t->lchild);
        cout<<t->data<<" ";
        midgo(t->rchild);
    }
}
void reargo(bst t) { //�������
    if(t) {
        reargo(t->lchild);
        reargo(t->rchild);
        cout<<t->data<<" ";
    }
}
int search(bst t,int n) {//���ö������������ֲ���
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

void levelgo(bst t,b_queue &q) {//��α���,����
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

void norecurmid(bst t,b_stack &s) { //�ǵݹ��������,ջ
    while(t!=NULL||s.base!=s.top) { //ֻ�б����겢��ջ���˲Ž���������һ��ջΪ���ǲ����ģ�
            //��Ϊһ��ʼ���ǿ�ջ������һ��tΪNULLҲ�ǲ����ģ���Ϊ��ֻ�����������һ����֧����ʱջ�Ƿǿյ�
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

