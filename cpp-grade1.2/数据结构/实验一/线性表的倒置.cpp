#include<stdio.h>
#include<malloc.h>
#define ERROR 0
#define OK 1
#define ElemType int
typedef struct LNode
{
    int data;
    struct LNode *next;
} LNode,*LinkList;
int CreateLink_L(LinkList &L,int n)
{
// 创建含有n个元素的单链表
    LinkList p,q;
    int i;
    ElemType e;
    L = (LinkList)malloc(sizeof(LNode));
    L->next = NULL;              // 先建立一个带头结点的单链表
    q = (LinkList)malloc(sizeof(LNode));
    q = L;
    for (i=0; i<n; i++)
    {
        scanf("%d", &e);
        p = (LinkList)malloc(sizeof(LNode));  // 生成新结点
        p->data=e;
        p->next=NULL;
        q->next=p;
        q=q->next;
    }
    return OK;
}
int LoadLink_L(LinkList &L)
{
// 单链表遍历
    LinkList p = L->next;
    if(p==NULL)
        printf("The List is empty!"); // 请填空
    else
    {
        while(p!=NULL)    // 请填空
        {
            printf("%d ",p->data);
            p=p->next;    // 请填空
        }
    }
    printf("\n");
    return OK;
}
int LinkInsert_L(LinkList &L,int i,ElemType e)
{
// 算法2.9
// 在带头结点的单链线性表L中第i个位置之前插入元素e
// 请补全代码
    LinkList p=L;
    int j=0;
    while(p&&j<i-1)
    {
        p=p->next;
        j++;
    }
    if(!p||j>i-1)
        return ERROR;
    LinkList s;
    s=(LinkList)malloc(sizeof(LNode));
    s->data=e;
    s->next=p->next;
    p->next=s;
    return OK;
}

int LinkDelete_L(LinkList &L,int i, ElemType &e)
{
// 算法2.10
// 在带头结点的单链线性表L中，删除第i个元素，并用e返回其值
// 请补全代码
    LinkList p=L;
    int j=0;
    while(p->next&&j<i-1)
    {
        p=p->next;
        ++j;
    }
    if(!(p->next)||j>i-1)
        return ERROR;
    LinkList q=p->next;
    p->next=q->next;
    e=q->data;
    free(q);
    return OK;
}
void turn_list(LinkList &T,int len)
{
    while(len--)
    {
        int e;
        LinkDelete_L(T,1,e);
        LinkInsert_L(T,len+1,e);
    }
}
int main()
{
    LinkList T;
    int len;
    scanf("%d",&len);
    printf("The List is:");
    CreateLink_L(T,len);
    LoadLink_L(T);
    turn_list(T,len);
    printf("The turned List is:");
    LoadLink_L(T);
    return 0;
}
