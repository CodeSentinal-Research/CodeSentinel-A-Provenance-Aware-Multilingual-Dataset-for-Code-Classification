#include<stdio.h>
#include<stdlib.h>
int cmp(const void*a,const void*b){return *(int*)a-*(int*)b;}
int main(){int m,n,k;scanf("%d %d %d",&m,&n,&k);int c[m+n];for(int i=0;i<m+n;i++)scanf("%d",&c[i]);qsort(c,m+n,sizeof(int),cmp);printf("%d\n",c[k-1]);}
