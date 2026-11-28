#include<stdio.h>
int main(){int n;scanf("%d",&n);int t[n],ans[n],stk[n],top=0;for(int i=0;i<n;i++){scanf("%d",&t[i]);ans[i]=0;}
for(int i=0;i<n;i++){while(top>0&&t[stk[top-1]]<t[i]){int j=stk[--top];ans[j]=i-j;}stk[top++]=i;}
for(int i=0;i<n;i++)printf("%d%c",ans[i],i<n-1?' ':'\n');}
