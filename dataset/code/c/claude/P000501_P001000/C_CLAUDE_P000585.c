#include<stdio.h>
int main(){int n;scanf("%d",&n);int a[n];for(int i=0;i<n;i++)scanf("%d",&a[i]);
int lo=0,hi=n-1;while(lo<=hi){printf("%d ",a[lo++]);if(lo<=hi)printf("%d ",a[hi--]);}printf("\n");}
