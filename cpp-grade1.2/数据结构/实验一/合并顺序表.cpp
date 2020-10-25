#include<stdio.h>
#include<malloc.h>
#define OK 1
#define ERROR 0
#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10
#define ElemType int

typedef int Status;
typedef struct
{
    int *elem;
    int length;
    int listsize;
}SqList;

Status InitList_Sq(SqList &L)
{  // �㷨2.3
  // ����һ���յ����Ա�L��
  L.elem = (ElemType *)malloc(LIST_INIT_SIZE*sizeof(ElemType));
  if (!L.elem) return OK;        // �洢����ʧ��
  L.length = 0;                  // �ձ���Ϊ0
  L.listsize = LIST_INIT_SIZE;   // ��ʼ�洢����
  return OK;
} // InitList_Sq

Status ListInsert_Sq(SqList &L, int i, ElemType e)
{  // �㷨2.4
  // ��˳�����Ա�L�ĵ�i��Ԫ��֮ǰ�����µ�Ԫ��e��
  // i�ĺϷ�ֵΪ1��i��ListLength_Sq(L)+1
  ElemType *p;
  if (i < 1 || i > L.length+1) return ERROR;  // iֵ���Ϸ�
  if (L.length >= L.listsize) {   // ��ǰ�洢�ռ���������������
    ElemType *newbase = (ElemType *)realloc(L.elem,
                  (L.listsize+LISTINCREMENT)*sizeof (ElemType));
    if (!newbase) return ERROR;   // �洢����ʧ��
    L.elem = newbase;             // �»�ַ
    L.listsize += LISTINCREMENT;  // ���Ӵ洢����
  }
  ElemType *q = &(L.elem[i-1]);   // qΪ����λ��
  for (p = &(L.elem[L.length-1]); p>=q; --p) *(p+1) = *p;
                                  // ����λ�ü�֮���Ԫ������
  *q = e;       // ����e
  ++L.length;   // ����1
  return OK;
} // ListInsert_Sq

Status ListDelete_Sq(SqList &L, int i, ElemType &e)
{  // �㷨2.5
  // ��˳�����Ա�L��ɾ����i��Ԫ�أ�����e������ֵ��
  // i�ĺϷ�ֵΪ1��i��ListLength_Sq(L)��
  ElemType *p, *q;
  if (i<1 || i>L.length) return ERROR;  // iֵ���Ϸ�
  p = &(L.elem[i-1]);                   // pΪ��ɾ��Ԫ�ص�λ��
  e = *p;                               // ��ɾ��Ԫ�ص�ֵ����e
  q = L.elem+L.length-1;                // ��βԪ�ص�λ��
  for (++p; p<=q; ++p) *(p-1) = *p;     // ��ɾ��Ԫ��֮���Ԫ������
  --L.length;                           // ����1
  return OK;
} // ListDelete_Sq

int main()
{
    SqList A,B,C;
    int lena,lenb;
    scanf("%d",&lena);
    InitList_Sq(A);//����˳���A
    for(int i=0;i<lena;i++)
    {
        int temp;
        scanf("%d",&temp);
        ListInsert_Sq(A,i+1,temp);
    }
    scanf("%d",&lenb);
    InitList_Sq(B);//����˳���B
    for(int i=0;i<lenb;i++)
    {
        int temp;
        scanf("%d",&temp);
        ListInsert_Sq(B,i+1,temp);
    }
    InitList_Sq(C);//����˳���C��
    C.elem=(int *)realloc(C.elem,(A.length+B.length)*sizeof(int));
    if(!C.elem) return 0;
    C.listsize=A.length+B.length;
    int *q,*w,*r;
    r=C.elem;
    q=A.elem;
    w=B.elem;
    while(q<=A.elem+A.length-1&&w<=B.elem+B.length-1)
    {
        if(*q>*w)
            *r++=*w++;
        else
            *r++=*q++;
    }
    //ִ���������ѭ����϶���һ�����һЩֵû�д�C����,������������
    while(q<=A.elem+A.length-1)
        *r++=*q++;
    while(w<=B.elem+B.length-1)
        *r++=*w++;
    printf("List A:");
        for(q=A.elem;q<A.elem+A.length;q++)
        printf("%d ",*q);
        printf("\n");
        printf("List B:");
        for(w=B.elem;w<B.elem+B.length;w++)
        printf("%d ",*w);
        printf("\n");
        printf("List C:");
        for(r=C.elem;r<C.elem+C.listsize;r++)
        printf("%d ",*r);
    return 0;
}

