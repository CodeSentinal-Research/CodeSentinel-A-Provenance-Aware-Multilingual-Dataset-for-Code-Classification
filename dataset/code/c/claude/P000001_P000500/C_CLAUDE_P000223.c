#include<stdio.h>
#include<stdlib.h>
typedef struct{int s,e;}A;
int cmp(const void*a,const void*b){return ((A*)a)->e-((A*)b)->e;}
int main(){int n;scanf("%d",&n);A a[n];for(int i=0;i<n;i++)scanf("%d %d",&a[i].s,&a[i].e);qsort(a,n,sizeof(A),cmp);int cnt=1,e=a[0].e;for(int i=1;i<n;i++)if(a[i].s>=e){cnt++;e=a[i].e;}printf("%d\n",cnt);}
