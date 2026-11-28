#include<stdio.h>
#include<stdlib.h>
int cmp(const void*a,const void*b){return *(int*)a-*(int*)b;}
int main(){int m,n;scanf("%d %d",&m,&n);int a[m+n];for(int i=0;i<m;i++)scanf("%d",&a[i]);for(int i=m;i<m+n;i++)scanf("%d",&a[i]);qsort(a,m+n,sizeof(int),cmp);int t=m+n;if(t%2)printf("%d\n",a[t/2]);else printf("%.1f\n",(a[t/2-1]+a[t/2])/2.0);}
