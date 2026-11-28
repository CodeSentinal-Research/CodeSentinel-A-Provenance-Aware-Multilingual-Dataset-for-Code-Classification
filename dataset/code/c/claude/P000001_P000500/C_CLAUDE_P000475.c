#include<stdio.h>
int main(){int x,n=100000;scanf("%d",&x);int a[n];for(int i=0;i<n;i++)scanf("%d",&a[i]);if(a[0]==x){printf("0\n");return 0;}int lo=0,hi=1;while(hi<n&&a[hi]<x){lo=hi;hi=hi*2<n?hi*2:n-1;}while(lo<=hi){int m=(lo+hi)/2;if(a[m]==x){printf("%d\n",m);return 0;}else if(a[m]<x)lo=m+1;else hi=m-1;}printf("-1\n");}
