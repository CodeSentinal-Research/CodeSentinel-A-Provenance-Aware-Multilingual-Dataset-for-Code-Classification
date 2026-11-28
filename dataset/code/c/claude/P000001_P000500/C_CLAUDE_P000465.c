#include<stdio.h>
int cmp(const void*a,const void*b){return *(int*)a-*(int*)b;}
int bs(int*a,int n,int x){int lo=0,hi=n-1;while(lo<=hi){int m=(lo+hi)/2;if(a[m]==x)return 1;if(a[m]<x)lo=m+1;else hi=m-1;}return 0;}
int main(){int n,d;scanf("%d %d",&n,&d);int a[n];for(int i=0;i<n;i++)scanf("%d",&a[i]);qsort(a,n,sizeof(int),cmp);for(int i=0;i<n;i++)if(bs(a,n,a[i]+d)&&a[i]+d!=a[i]){printf("Yes\n");return 0;}printf("No\n");}
