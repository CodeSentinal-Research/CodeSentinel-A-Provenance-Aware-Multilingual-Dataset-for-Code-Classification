#include<stdio.h>
int main(){int n;scanf("%d",&n);int cnt=0;for(int i=0;i<n*n;i++){int x;scanf("%d",&x);if(x==0)cnt++;}printf("%d\n",cnt);}
