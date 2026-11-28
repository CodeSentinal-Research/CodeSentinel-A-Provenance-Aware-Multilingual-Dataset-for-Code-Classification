#include<stdio.h>
#include<stdlib.h>
int main(){int n,x;scanf("%d %d",&n,&x);int a[n];for(int i=0;i<n;i++)scanf("%d",&a[i]);int lo=0,hi=n-1;while(lo<hi){if(abs(a[lo]-x)<=abs(a[hi]-x))hi--;else lo++;}printf("%d\n",a[lo]);}
