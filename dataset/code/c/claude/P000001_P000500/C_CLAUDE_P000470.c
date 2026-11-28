#include<stdio.h>
#include<stdlib.h>
int main(){int n,x;scanf("%d %d",&n,&x);int a[n];for(int i=0;i<n;i++)scanf("%d",&a[i]);int lo=0,hi=n-1;while(lo<hi){int m=(lo+hi)/2;if(a[m]<x)lo=m+1;else hi=m;}if(lo>0&&abs(a[lo-1]-x)<abs(a[lo]-x))lo--;printf("%d\n",a[lo]);}
