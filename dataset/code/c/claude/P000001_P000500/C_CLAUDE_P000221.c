#include<stdio.h>
#include<stdlib.h>
typedef struct{int a,b;}P;
int cmp(const void*x,const void*y){return ((P*)x)->b-((P*)y)->b;}
int main(){int n;scanf("%d",&n);P p[n];for(int i=0;i<n;i++)scanf("%d %d",&p[i].a,&p[i].b);qsort(p,n,sizeof(P),cmp);int cnt=1,e=p[0].b;for(int i=1;i<n;i++)if(p[i].a>e){cnt++;e=p[i].b;}printf("%d\n",cnt);}
