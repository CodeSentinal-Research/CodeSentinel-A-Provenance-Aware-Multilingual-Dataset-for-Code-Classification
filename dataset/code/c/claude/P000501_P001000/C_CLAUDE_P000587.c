#include<stdio.h>
#include<stdlib.h>
int cmp(const void*a,const void*b){return *(int*)a-*(int*)b;}
int main(){int k;scanf("%d",&k);int all[100001],total=0;
for(int i=0;i<k;i++){int sz;scanf("%d",&sz);for(int j=0;j<sz;j++)scanf("%d",&all[total++]);}
qsort(all,total,sizeof(int),cmp);for(int i=0;i<total;i++)printf("%d%c",all[i],i<total-1?' ':'\n');}
