#include<stdio.h>
int main(){int n;scanf("%d",&n);int a[n];for(int i=0;i<n;i++)scanf("%d",&a[i]);int lo=0,hi=n-1;while(lo<hi){int m=(lo+hi+1)/2;if(a[m]>=a[lo])lo=m;else hi=m-1;}printf("%d\n",a[lo]);}
