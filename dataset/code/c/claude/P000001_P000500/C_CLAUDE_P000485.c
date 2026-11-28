#include<stdio.h>
int main(){int n;scanf("%d",&n);int a[n],stk[n],top=0;for(int i=0;i<n;i++)scanf("%d",&a[i]);for(int i=0;i<n;i++){int x=a[i],alive=1;while(alive&&x<0&&top>0&&stk[top-1]>0){if(stk[top-1]<-x)top--;else if(stk[top-1]==-x){top--;alive=0;}else alive=0;}if(alive)stk[top++]=x;}for(int i=0;i<top;i++)printf("%d%c",stk[i],i<top-1?' ':'\n');}
