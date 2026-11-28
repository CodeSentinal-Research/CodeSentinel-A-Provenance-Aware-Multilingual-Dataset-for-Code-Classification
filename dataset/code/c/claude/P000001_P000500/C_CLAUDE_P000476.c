#include<stdio.h>
int main(){int n;scanf("%d",&n);int a[n];for(int i=0;i<n;i++)scanf("%d",&a[i]);int lo=0,hi=n-1;while(lo<hi){int m=(lo+hi)/2;if(m%2==1)m--;if(a[m]==a[m+1])lo=m+2;else hi=m;}printf("%d\n",a[lo]);}
