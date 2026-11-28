#include<stdio.h>
int main(){int sz;scanf("%d",&sz);int a[sz];for(int i=0;i<sz;i++)scanf("%d",&a[i]);int n;scanf("%d",&n);
int idx=sz-n;for(int i=idx;i<sz-1;i++)a[i]=a[i+1];sz--;
for(int i=0;i<sz;i++)printf("%d%c",a[i],i<sz-1?' ':'\n');}
