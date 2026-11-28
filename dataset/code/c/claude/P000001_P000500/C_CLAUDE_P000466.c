#include<stdio.h>
int cmp(const void*a,const void*b){return *(int*)a-*(int*)b;}
int main(){int n,t;scanf("%d %d",&n,&t);int a[n];for(int i=0;i<n;i++)scanf("%d",&a[i]);qsort(a,n,sizeof(int),cmp);for(int i=0;i<n-2;i++){int lo=i+1,hi=n-1;while(lo<hi){int s=a[i]+a[lo]+a[hi];if(s==t){printf("Yes\n");return 0;}else if(s<t)lo++;else hi--;}}printf("No\n");}
