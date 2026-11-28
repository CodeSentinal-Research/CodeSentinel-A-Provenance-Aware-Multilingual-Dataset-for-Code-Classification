#include<stdio.h>
int lb(int*a,int n,int x){int lo=0,hi=n,m;while(lo<hi){m=(lo+hi)/2;if(a[m]<x)lo=m+1;else hi=m;}return lo;}
int ub(int*a,int n,int x){int lo=0,hi=n,m;while(lo<hi){m=(lo+hi)/2;if(a[m]<=x)lo=m+1;else hi=m;}return lo;}
int main(){int n,x;scanf("%d %d",&n,&x);int a[n];for(int i=0;i<n;i++)scanf("%d",&a[i]);printf("%d\n",ub(a,n,x)-lb(a,n,x));}
