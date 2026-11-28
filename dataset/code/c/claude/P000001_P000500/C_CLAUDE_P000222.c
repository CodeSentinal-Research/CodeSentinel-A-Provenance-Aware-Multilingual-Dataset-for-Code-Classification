#include<stdio.h>
#include<stdlib.h>
int cmp(const void*a,const void*b){return *(int*)a-*(int*)b;}
int main(){int n;scanf("%d",&n);int a[n],d[n];for(int i=0;i<n;i++)scanf("%d",&a[i]);for(int i=0;i<n;i++)scanf("%d",&d[i]);qsort(a,n,sizeof(int),cmp);qsort(d,n,sizeof(int),cmp);int p=1,res=1,i=1,j=0;while(i<n&&j<n){if(a[i]<=d[j]){p++;i++;}else{p--;j++;}if(p>res)res=p;}printf("%d\n",res);}
