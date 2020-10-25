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
{  // 算法2.3
  // 构造一个空的线性表L。
  L.elem = (ElemType *)malloc(LIST_INIT_SIZE*sizeof(ElemType));
  if (!L.elem) return OK;        // 存储分配失败
  L.length = 0;                  // 空表长度为0
  L.listsize = LIST_INIT_SIZE;   // 初始存储容量
  return OK;
} // InitList_Sq

Status ListInsert_Sq(SqList &L, int i, ElemType e)
{  // 算法2.4
  // 在顺序线性表L的第i个元素之前插入新的元素e，
  // i的合法值为1≤i≤ListLength_Sq(L)+1
  ElemType *p;
  if (i < 1 || i > L.length+1) return ERROR;  // i值不合法
  if (L.length >= L.listsize) {   // 当前存储空间已满，增加容量
    ElemType *newbase = (ElemType *)realloc(L.elem,
                  (L.listsize+LISTINCREMENT)*sizeof (ElemType));
    if (!newbase) return ERROR;   // 存储分配失败
    L.elem = newbase;             // 新基址
    L.listsize += LISTINCREMENT;  // 增加存储容量
  }
  ElemType *q = &(L.elem[i-1]);   // q为插入位置
  for (p = &(L.elem[L.length-1]); p>=q; --p) *(p+1) = *p;
                                  // 插入位置及之后的元素右移
  *q = e;       // 插入e
  ++L.length;   // 表长增1
  return OK;
} // ListInsert_Sq

Status ListDelete_Sq(SqList &L, int i, ElemType &e)
{  // 算法2.5
  // 在顺序线性表L中删除第i个元素，并用e返回其值。
  // i的合法值为1≤i≤ListLength_Sq(L)。
  ElemType *p, *q;
  if (i<1 || i>L.length) return ERROR;  // i值不合法
  p = &(L.elem[i-1]);                   // p为被删除元素的位置
  e = *p;                               // 被删除元素的值赋给e
  q = L.elem+L.length-1;                // 表尾元素的位置
  for (++p; p<=q; ++p) *(p-1) = *p;     // 被删除元素之后的元素左移
  --L.length;                           // 表长减1
  return OK;
} // ListDelete_Sq

int main()
{
    SqList A,B,C;
    int lena,lenb;
    scanf("%d",&lena);
    InitList_Sq(A);//建立顺序表A
    for(int i=0;i<lena;i++)
    {
        int temp;
        scanf("%d",&temp);
        ListInsert_Sq(A,i+1,temp);
    }
    scanf("%d",&lenb);
    InitList_Sq(B);//建立顺序表B
    for(int i=0;i<lenb;i++)
    {
        int temp;
        scanf("%d",&temp);
        ListInsert_Sq(B,i+1,temp);
    }
    InitList_Sq(C);//建立顺序表C；
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
    //执行完上面的循环后肯定有一个表的一些值没有打到C上面,下面两个继续
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

