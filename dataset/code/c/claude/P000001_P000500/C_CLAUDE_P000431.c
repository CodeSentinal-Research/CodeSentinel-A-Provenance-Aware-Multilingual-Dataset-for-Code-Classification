#include<stdio.h>
int main(){int n,x,cnt=0;scanf("%d %d",&n,&x);for(int i=0;i<n;i++){int v;scanf("%d",&v);if(v==x)cnt++;}printf("%d\n",cnt);}
