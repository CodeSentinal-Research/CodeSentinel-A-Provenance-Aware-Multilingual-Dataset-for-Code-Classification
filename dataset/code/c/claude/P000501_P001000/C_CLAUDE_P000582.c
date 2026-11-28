#include<stdio.h>
int main(){int n;scanf("%d",&n);int prev=-1000001,v;for(int i=0;i<n;i++){scanf("%d",&v);if(v!=prev){printf("%d ",v);prev=v;}}printf("\n");}
