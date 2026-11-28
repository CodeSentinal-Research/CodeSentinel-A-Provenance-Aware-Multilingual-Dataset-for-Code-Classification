#include<stdio.h>
int main(){int n;scanf("%d",&n);int a[n],res[n];for(int i=0;i<n;i++)scanf("%d",&a[i]);for(int i=0;i<n;i++){res[i]=0;for(int j=i+1;j<n;j++)if(a[j]<a[i])res[i]++;}for(int i=0;i<n;i++)printf("%d%c",res[i],i<n-1?' ':'\n');}
