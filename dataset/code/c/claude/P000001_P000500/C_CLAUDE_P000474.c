#include<stdio.h>
int main(){int n;scanf("%d",&n);int a[n];for(int i=0;i<n;i++)scanf("%d",&a[i]);int lo=0,hi=n-1;while(lo<hi){int m=(lo+hi)/2;if(a[m]<a[m+1])lo=m+1;else hi=m;}printf("%d\n",a[lo]);}
