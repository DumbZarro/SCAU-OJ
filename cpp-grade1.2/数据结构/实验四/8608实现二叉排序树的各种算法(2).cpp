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

void grow(bst &t,int data) { //����������/����
    if(t==NULL) {
        t= new node;
        t->data=data;
        t->lchild=t->rchild=NULL;
    } else if(data >= t->data)
        grow(t->rchild,data);
    else if(data < t->data)
        grow(t->lchild,data);
}

void pre_go(bst t) {//�������
    if(t) {
        cout<<t->data<<" ";
        pre_go(t->lchild);
        pre_go(t->rchild);
    }
}

void mid_go(bst t) {//�������
    if(t) {
        mid_go(t->lchild);
        cout<<t->data<<" ";
        mid_go(t->rchild);
    }

}
void rear_go(bst t) {//�������
    if(t) {
        rear_go(t->lchild);
        rear_go(t->rchild);
        cout<<t->data<<" ";
    }

}

void search_node(bst t,int num) {//����
    if(t==NULL)
        cout<<"0"<<endl;//�����������д��ǰ��
    else if(t->data==num)
        cout<<"1"<<endl;
    else if(t->data<num)
        search_node(t->rchild,num);
    else if(t->data>num)
        search_node(t->lchild,num);

}

void none_recursive_mid(bst t,stack<bst> &s) { //�ǵݹ��������
    while(!s.empty()||t) {
        if(t) {
            s.push(t);
            t=t->lchild;
        } else {
            t=s.top();//����ջ��Ԫ��
            cout<<t->data<<" ";
            s.pop();//����ջ��Ԫ��
            t=t->rchild;
        }
    }
    cout<<endl;
}

void level_go(bst t,queue<bst> q) {//��α���
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

void change(bst &t) {//�ݹ齻�����������ҽڵ�
    if(!t)
        return ;
    swap(t->lchild,t->rchild);
    change(t->lchild);
    change(t->rchild);
}

int tree_depth(bst t) {//�ݹ�����������
    if(!t)
        return 0;
    return max(tree_depth(t->lchild),tree_depth(t->rchild))+1;
}

int leaf_node(bst t) {//��Ҷ������
    if(!t)
        return 0;
    if(!t->lchild&&!t->rchild)
        return 1;
    return leaf_node(t->lchild)+leaf_node(t->rchild);
}
int main() {
    bst T=NULL;
    //������
    int m,data;
    cin>>m;
    for(int i=0; i<=m-1; i++) {
        cin>>data;
        grow(T,data);
    }
    //���к����ӡ
    pre_go(T);
    cout<<endl;
    mid_go(T);
    cout<<endl;
    rear_go(T);
    cout<<endl;
    //����
    int num;
    cin>>num;
    search_node(T,num);
    cin>>num;
    search_node(T,num);
    //����
    cin>>data;
    grow(T,data);
    //���к����ӡ
    pre_go(T);
    cout<<endl;
    mid_go(T);
    cout<<endl;
    rear_go(T);
    cout<<endl;
    //�ǵݹ��������
    stack<bst> s;
    none_recursive_mid(T,s);
    //��α���
    queue<bst> q;
    level_go(T,q);
    //��������
    change(T);
    //���к����ӡ
    pre_go(T);
    cout<<endl;
    mid_go(T);
    cout<<endl;
    rear_go(T);
    cout<<endl;
    //��������
    change(T);
    //���к����ӡ
    pre_go(T);
    cout<<endl;
    mid_go(T);
    cout<<endl;
    rear_go(T);
    cout<<endl;
    //�������
    cout<<tree_depth(T)<<endl;
    //Ҷ�ӽ������
    cout<<leaf_node(T)<<endl;
    return 0;
}

