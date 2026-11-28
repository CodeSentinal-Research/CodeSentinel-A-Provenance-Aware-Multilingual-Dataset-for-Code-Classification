#include<stdio.h>
int main(){int n;scanf("%d",&n);int ps[10001],sp[10001],stk[10001][2],top=0;for(int i=0;i<n;i++){int p;scanf("%d",&p);int span=1;while(top>0&&stk[top-1][0]<=p){span+=stk[top-1][1];top--;}stk[top][0]=p;stk[top][1]=span;top++;printf("%d\n",span);}}
