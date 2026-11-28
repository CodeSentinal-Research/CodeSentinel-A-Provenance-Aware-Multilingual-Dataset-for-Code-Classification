#include<stdio.h>
int main(){int n,x;scanf("%d %d",&n,&x);for(int i=0;i<n;i++){int v;scanf("%d",&v);if(v==x){printf("%d\n",i);return 0;}}printf("-1\n");}
