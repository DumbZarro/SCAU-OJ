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
// ��������n��Ԫ�صĵ�����
    LinkList p,q;
    int i;
    ElemType e;
    L = (LinkList)malloc(sizeof(LNode));
    L->next = NULL;              // �Ƚ���һ����ͷ���ĵ�����
    q = (LinkList)malloc(sizeof(LNode));
    q = L;
    for (i=0; i<n; i++)
    {
        scanf("%d", &e);
        p = (LinkList)malloc(sizeof(LNode));  // �����½��
        p->data=e;
        p->next=NULL;
        q->next=p;
        q=q->next;
    }
    return OK;
}
int LoadLink_L(LinkList &L)
{
// ���������
    LinkList p = L->next;
    if(p==NULL)
        printf("The List is empty!"); // �����
    else
    {
        while(p!=NULL)    // �����
        {
            printf("%d ",p->data);
            p=p->next;    // �����
        }
    }
    printf("\n");
    return OK;
}
int LinkInsert_L(LinkList &L,int i,ElemType e)
{
// �㷨2.9
// �ڴ�ͷ���ĵ������Ա�L�е�i��λ��֮ǰ����Ԫ��e
// �벹ȫ����
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
// �㷨2.10
// �ڴ�ͷ���ĵ������Ա�L�У�ɾ����i��Ԫ�أ�����e������ֵ
// �벹ȫ����
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
