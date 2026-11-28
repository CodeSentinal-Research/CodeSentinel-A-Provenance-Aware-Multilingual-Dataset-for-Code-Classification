#include<stdio.h>
int main(){int n;scanf("%d",&n);int h[n],ans[n],stk[n],top=0;
for(int i=0;i<n;i++)scanf("%d",&h[i]);
for(int i=n-1;i>=0;i--){int cnt=0;
    while(top>0&&stk[top-1]<h[i]){top--;cnt++;}
    if(top>0)cnt++;ans[i]=cnt;stk[top++]=h[i];}
for(int i=0;i<n;i++)printf("%d%c",ans[i],i<n-1?' ':'\n');}
