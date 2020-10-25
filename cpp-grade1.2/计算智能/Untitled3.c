#include<stdio.h>

#define MAXSIZE 100

typedef int Keytype;

typedef struct

{

Keytype key;

} recordtype;

typedef struct

{

recordtype r[MAXSIZE+1];

int length;

} table;

void visit(table *t)

{

int i;

for(i=1; i<=t->length; i++)

printf("%d ",t->r[i].key);
}

void merge(table *tabs,table *tabg,int u,int m,int v) {

int i,j,k,t;

i=u;

j=m+1;

k=u;

while(i<=m&&j<=v)

{

if(tabs->r[i].key<=tabs->r[j].key) {

tabg->r[k]=tabs->r[i];

i++;

}

else

{

tabg->r[k]=tabs->r[j];

j++;

}

k++;

}

if(i<=m)

for(t=i; t<=m; t++)
tabg->r[k+t-i]=tabs->r[t]; else

for(t=j; t<=v; t++)

tabg->r[k+t-j]=tabs->r[t]; }

void mergepass(table *tabs,table *tabg,int len) {

int i,j,n;

n=tabg->length=tabs->length; i=1;

while(i<=n-2*len+1)

{

merge(tabs,tabg,i,i+len-1,i+2*len-1); i=i+2*len;

}

if(i+len-1
merge(tabs,tabg,i,i+len-1,n); else


tabg->r[j]=tabs->r[j]; }

void mergesort(table *tab)

{

int len;

table temp;

len=1;

while(lenlength)

{

mergepass(tab,&temp,len); visit(&temp);

printf("\n");

len=2*len;

*tab=temp;

}

}

int main()

{

int i;

table tab;

scanf("%d",&tab.length);

for(i=1; i<=tab.length; i++)

scanf("%d",&tab.r[i].key); mergesort(&tab);

return 0;

}
