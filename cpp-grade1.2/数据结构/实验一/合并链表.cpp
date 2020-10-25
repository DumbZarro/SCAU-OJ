#include<stdio.h>
#include<malloc.h>
#define ERROR 0
#define OK 1
#define ElemType int
typedef struct LNode{
    int data;
    struct LNode *next;
}LNode,*LinkList;

int CreateLink_L(LinkList &L,int n){
// ��������n��Ԫ�صĵ�����
    LinkList p,q;
    int i;
    ElemType e;
    L = (LinkList)malloc(sizeof(LNode));
    L->next = NULL;              // �Ƚ���һ����ͷ���ĵ�����
    q = (LinkList)malloc(sizeof(LNode));
    q = L;
    for (i=0; i<n; i++) {
        scanf("%d", &e);
        p = (LinkList)malloc(sizeof(LNode));  // �����½��
        p->data=e;
        p->next=NULL;
        q->next=p;
        q=q->next;
    }
    return OK;
}
int LoadLink_L(LinkList &L){
    // ���������
    LinkList p = L->next;
    if(p==NULL)printf("The List is empty!"); // �����
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

int LinkInsert_L(LinkList &L,int i,ElemType e){
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
    if(!p||j>i-1) return ERROR;
    LinkList s;
    s=(LinkList)malloc(sizeof(LNode));
    s->data=e;
    s->next=p->next;
    p->next=s;
    return OK;
}

int LinkDelete_L(LinkList &L,int i, ElemType &e){
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
    if(!(p->next)||j>i-1) return ERROR;
    LinkList q=p->next;
    p->next=q->next;
    e=q->data;
    free(q);
    return OK;
}

void MergeList_L(LinkList &La,LinkList &Lb,LinkList &Lc)
{
    LinkList pa,pb,pc;
    pa=La->next;
    pb=Lb->next;
    pc=Lc=La;
    while(pa&&pb)
    {
        if(pa->data>pb->data)
        {
            pc->next=pb;
            pc=pb;
            pb=pb->next;
        }
        else
        {
            pc->next=pa;
            pc=pa;
            pa=pa->next;
        }
    }
    pc->next=pa?pa:pb;
    free(Lb);
}
int main()
{
    LinkList T1,T2,T;
    int n1,n2;
    scanf("%d",&n1);
    CreateLink_L(T1,n1);
    printf("List A:");
    LoadLink_L(T1);
    scanf("%d",&n2);

    CreateLink_L(T2,n2);
    printf("List B:");
    LoadLink_L(T2);
    MergeList_L(T1,T2,T);
    printf("List C:");
    LoadLink_L(T);
    return 0;
}
