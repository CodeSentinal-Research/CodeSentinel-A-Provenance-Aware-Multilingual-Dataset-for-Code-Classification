#include<stdio.h>
int main(){int n,x;scanf("%d %d",&n,&x);int a[n];for(int i=0;i<n;i++)scanf("%d",&a[i]);int lo=0,hi=n-1;while(lo<=hi){int m=(lo+hi)/2;if(a[m]==x){printf("%d\n",m);return 0;}if(a[lo]<=a[m]){if(a[lo]<=x&&x<a[m])hi=m-1;else lo=m+1;}else{if(a[m]<x&&x<=a[hi])lo=m+1;else hi=m-1;}}printf("-1\n");}
