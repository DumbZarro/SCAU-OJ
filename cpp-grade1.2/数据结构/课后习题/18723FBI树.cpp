#include<iostream>
#include<string>
using namespace std;
int a[1030];
struct node {
    char data;
    node *lchild,*rchild;
};

char tp(int left,int right) {
    int flag1=0,flag2=0;
    for(int i=left; i<=right; i++) {
        if(a[i] == 0)
            flag1=1;
        else if(a[i] == 1)
            flag2=1;
    }
    if(flag1 == 1 && flag2 == 0)
        return 'B';
    else if(flag1 == 0 && flag2 ==1)
        return 'I';
    else if(flag1 == 1 && flag2 == 1)
        return 'F';
}

node* newNode(int left,int right) {
    node *Node=new node;
    Node->data=tp(left,right);
    Node->lchild=Node->rchild=NULL;
    return Node;
}

node* create(int left,int right) {
    node *root=NULL;
    if(left != right) {
        int mid=(left+right)/2;
        root=newNode(left,right);
        root->lchild=create(left,mid);
        root->rchild=create(mid+1,right);
        return root;
    } else
        return newNode(left,right);
}

void postOrder(node *root) {
    if(root == NULL)
        return;
    postOrder(root->lchild);
    postOrder(root->rchild);
    cout<<root->data;
}

int main() {
    int n;
    cin>>n;
    string str;
    cin>>str;
    n=str.length();
    for(int i=1; i<=str.length(); i++) {
        a[i]=str[i-1]-'0';
    }
    node *root=NULL;
    root=create(1,n);
    postOrder(root);
    return 0;
}
