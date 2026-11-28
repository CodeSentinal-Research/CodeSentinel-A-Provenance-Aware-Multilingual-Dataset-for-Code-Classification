#include<stdio.h>
int main(){int n,x;scanf("%d %d",&n,&x);int a[n];for(int i=0;i<n;i++)scanf("%d",&a[i]);int lo=0,hi=n-1,res=-1;while(lo<=hi){int m=(lo+hi)/2;if(a[m]<=x){res=a[m];lo=m+1;}else hi=m-1;}printf("%d\n",res);}
