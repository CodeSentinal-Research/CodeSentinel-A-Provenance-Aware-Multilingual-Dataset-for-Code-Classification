#include<stdio.h>
int main(){int n,x;scanf("%d %d",&n,&x);int a[n];for(int i=0;i<n;i++)scanf("%d",&a[i]);int first=-1,last=-1;for(int i=0;i<n;i++)if(a[i]==x){if(first==-1)first=i;last=i;}printf("%d %d\n",first,last);}
