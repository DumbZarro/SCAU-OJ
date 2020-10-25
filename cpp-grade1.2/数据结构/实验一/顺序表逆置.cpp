#include<iostream>
#include<malloc.h>
#define OK 1
#define ERROR 0
#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10
#define ElemType int
using namespace std;
typedef int Status;
typedef struct
{
    int *elem;
    int length;
    int listsize;
}SqList;

Status InitList_Sq(SqList &L,int n)//³õÊ¼»¯º¯Êý
{
  L.elem = (ElemType *)malloc(LIST_INIT_SIZE*sizeof(ElemType));
  if (!L.elem) return ERROR;// ´æ´¢·ÖÅäÊ§°Ü
  L.listsize = LIST_INIT_SIZE;
  for(int i=0;i<=n-1;i++)   cin>>L.elem[i];
  L.length = n;
  return OK;
}

Status sort(SqList &L,int n)//µ¹Ðòº¯Êý
{
  int i,j,k;
  for(i=0;i<=(n-1)/2;i++)
  {
      k=L.elem[i];
      L.elem[i]=L.elem[n-i-1];
      L.elem[n-i-1]=k;;
  }
  return OK;
}


int main()
{
    int i,j,k,n,m;
    SqList x;
    cin>>n;
    if(InitList_Sq(x,n))
    {
        cout<<"The List is:";
        for(i=0;i<=n-1;i++) cout<<x.elem[i]<<' ';
        cout<<endl;
    }

    if(sort(x,n))
    {
        cout<<"The turned List is:";
        for(i=0;i<=n-1;i++) cout<<x.elem[i]<<' ';
        cout<<endl;
    }
return 0;
}

