#include<stdio.h>
int lb(int*a,int n,int x){int lo=0,hi=n;while(lo<hi){int m=(lo+hi)/2;if(a[m]<x)lo=m+1;else hi=m;}return lo;}
int ub(int*a,int n,int x){int lo=0,hi=n;while(lo<hi){int m=(lo+hi)/2;if(a[m]<=x)lo=m+1;else hi=m;}return lo;}
int main(){int n,x;scanf("%d %d",&n,&x);int a[n];for(int i=0;i<n;i++)scanf("%d",&a[i]);int l=lb(a,n,x),r=ub(a,n,x)-1;if(l<=r&&a[l]==x)printf("%d %d\n",l,r);else printf("-1 -1\n");}
