#include<stdio.h>
int main(){int n;scanf("%d",&n);int a[n],x;for(int i=0;i<n;i++)scanf("%d",&a[i]);scanf("%d",&x);int idx=-1;for(int i=0;i<n;i++)if(a[i]==x)idx=i;printf("%d\n",idx);}
