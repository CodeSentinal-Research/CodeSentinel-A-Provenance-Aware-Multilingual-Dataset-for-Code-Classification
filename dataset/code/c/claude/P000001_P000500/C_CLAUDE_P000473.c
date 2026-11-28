#include<stdio.h>
int main(){int n,x;scanf("%d %d",&n,&x);int a[n];for(int i=0;i<n;i++)scanf("%d",&a[i]);int lo=0,hi=n-1;while(lo<=hi){int m=(lo+hi)/2;if(a[m]==x){printf("%d\n",m);return 0;}if(m>lo&&a[m-1]==x){printf("%d\n",m-1);return 0;}if(m<hi&&a[m+1]==x){printf("%d\n",m+1);return 0;}if(a[m]<x)lo=m+2;else hi=m-2;}printf("-1\n");}
