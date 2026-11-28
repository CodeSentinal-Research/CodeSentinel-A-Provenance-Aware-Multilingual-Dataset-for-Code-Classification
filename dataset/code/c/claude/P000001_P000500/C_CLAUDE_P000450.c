#include<stdio.h>
int main(){int n,k;scanf("%d %d",&n,&k);int a[n];for(int i=0;i<n;i++)scanf("%d",&a[i]);int lo=0,hi=n;while(lo<hi){int m=(lo+hi)/2;if(a[m]-(m+1)>=k)hi=m;else lo=m+1;}printf("%d\n",lo+k);}
