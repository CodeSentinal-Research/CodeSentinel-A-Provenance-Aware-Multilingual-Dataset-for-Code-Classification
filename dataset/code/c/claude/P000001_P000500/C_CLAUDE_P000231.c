#include<stdio.h>
#include<stdlib.h>
int cmp(const void*a,const void*b){return *(int*)a-*(int*)b;}
int main(){int n;scanf("%d",&n);int a[n*n];for(int i=0;i<n*n;i++)scanf("%d",&a[i]);qsort(a,n*n,sizeof(int),cmp);for(int i=0;i<n*n;i++)printf("%d%c",a[i],i<n*n-1?' ':\'\\n');}
