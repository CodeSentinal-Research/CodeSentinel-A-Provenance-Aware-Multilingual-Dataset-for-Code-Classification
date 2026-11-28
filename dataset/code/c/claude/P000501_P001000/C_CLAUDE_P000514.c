#include<stdio.h>
#include<stdlib.h>
int cmp(const void*a,const void*b){return *(int*)a-*(int*)b;}
int main(){int n;scanf("%d",&n);int a[n];for(int i=0;i<n;i++)scanf("%d",&a[i]);
qsort(a,n,sizeof(int),cmp);
int ans=a[n-1]-a[2];
if(a[n-2]-a[1]<ans)ans=a[n-2]-a[1];
if(a[n-3]-a[0]<ans)ans=a[n-3]-a[0];
printf("%d\n",ans<0?0:ans);}
