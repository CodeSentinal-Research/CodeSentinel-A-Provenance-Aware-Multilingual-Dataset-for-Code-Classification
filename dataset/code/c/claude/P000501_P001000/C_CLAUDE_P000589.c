#include<stdio.h>
int main(){int n;scanf("%d",&n);int a[n];for(int i=0;i<n;i++)scanf("%d",&a[i]);int val;scanf("%d",&val);
int j=0;for(int i=0;i<n;i++)if(a[i]!=val){a[j++]=a[i];break;}
for(int i=j;i<n;i++)a[j++]=a[i];n=j;
for(int i=0;i<n;i++)printf("%d%c",a[i],i<n-1?' ':'\n');}
