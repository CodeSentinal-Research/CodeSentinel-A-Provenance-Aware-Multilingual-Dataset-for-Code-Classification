#include<stdio.h>
int cmp(const void*a,const void*b){return *(int*)a-*(int*)b;}
int main(){int n;scanf("%d",&n);int a[n];for(int i=0;i<n;i++)scanf("%d",&a[i]);int orig[n];for(int i=0;i<n;i++)orig[i]=a[i];qsort(a,n,sizeof(int),cmp);for(int i=1;i<n;i++)if(a[i]==a[i-1]){printf("%d\n",a[i]);return 0;}printf("-1\n");}
