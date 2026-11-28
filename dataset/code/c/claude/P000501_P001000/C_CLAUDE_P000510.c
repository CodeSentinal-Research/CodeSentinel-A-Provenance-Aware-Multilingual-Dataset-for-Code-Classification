#include<stdio.h>
int main(){int n;scanf("%d",&n);int p[n],res[n],stk[n],top=0;
for(int i=0;i<n;i++){scanf("%d",&p[i]);res[i]=p[i];}
for(int i=0;i<n;i++){while(top>0&&p[stk[top-1]]>=p[i]){res[stk[--top]]-=p[i];}stk[top++]=i;}
for(int i=0;i<n;i++)printf("%d%c",res[i],i<n-1?' ':'\n');}
