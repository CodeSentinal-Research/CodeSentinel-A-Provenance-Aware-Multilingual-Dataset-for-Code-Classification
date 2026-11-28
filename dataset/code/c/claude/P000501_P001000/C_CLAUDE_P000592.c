#include<stdio.h>
int main(){int n;scanf("%d",&n);int a[n];for(int i=0;i<n;i++)scanf("%d",&a[i]);int val;scanf("%d",&val);
int j=0;for(int i=0;i<n;i++)if(a[i]!=val)a[j++]=a[i];
for(int i=0;i<j;i++)printf("%d%c",a[i],i<j-1?' ':'\n');}
