#include<stdio.h>
#include<malloc.h>
#define ERROR 0
#define OK 1
#define ElemType int

typedef struct LNode
{
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
        // �벹ȫ����
        p->data=e;
        q->next=p;
        p->next=NULL;
        q=p;
    }
    return OK;
}

int LoadLink_L(LinkList &L){
    // ���������
    LinkList p = L->next;
    if(p==NULL)printf("The List is empty!"); // �����
    else
    {
        printf("The LinkList is:");
        while(p!=NULL)    // �����
        {
            printf("%d ",p->data);
            p=p->next;   // �����
        }
    }
    printf("\n");
    return OK;
}

int LinkInsert_L(LinkList &L,int i,ElemType e){
    // �㷨2.9
    // �ڴ�ͷ���ĵ������Ա�L�е�i��λ��֮ǰ����Ԫ��e
    // �벹ȫ����
    LinkList p = L,q;
    int j;
    for(j=1;j<=i-1;j++){
        p=p->next;
    }
    q = (LinkList)malloc(sizeof(LNode));  // �����½��
    q->data=e;
    q->next=p->next;
    p->next=q;
    return OK;
}

int LinkDelete_L(LinkList &L,int i, ElemType &e){
// �㷨2.10
// �ڴ�ͷ���ĵ������Ա�L�У�ɾ����i��Ԫ�أ�����e������ֵ
// �벹ȫ����
    LinkList p = L,q;
    int j;
    for(j=0;j<i-1;j++){
        p=p->next;
    }
    q = (LinkList)malloc(sizeof(LNode));
    q=p->next;
    e=q->data;
    p->next=q->next;
    return OK;
}

int main()
{
    LinkList T;
    int a,n,i;
    ElemType x, e;
    printf("Please input the init size of the linklist:\n");
    scanf("%d",&n);
    printf("Please input the %d element of the linklist:\n", n);
    if(CreateLink_L(T,n))     // �ж������Ƿ񴴽��ɹ��������
    {
        printf("A Link List Has Created.\n");
        LoadLink_L(T);
    }
    while(1)
	{
		printf("1:Insert element\n2:Delete element\n3:Load all elements\n0:Exit\nPlease choose:\n");
		scanf("%d",&a);
		switch(a)
		{
			case 1: scanf("%d%d",&i,&x);
				  if(i<1||i>n+1||!LinkInsert_L(T,i,x)) printf("Insert Error!\n");
				  // �ж�iֵ�Ƿ�Ϸ��������
				  else {
                    n++;
                    printf("The Element %d is Successfully Inserted!\n", x);
				  }
				  break;
			case 2: scanf("%d",&i);
				  if(i<1||i>n||!LinkDelete_L(T,i,e)) printf("Delete Error!\n");
				  // �ж�iֵ�Ƿ�Ϸ��������
				  else {
                    n--;
                    printf("The Element %d is Successfully Deleted!\n", e);
				  }
				  break;
			case 3: LoadLink_L(T);
				  break;
			case 0: return 1;
		}
	}
}
