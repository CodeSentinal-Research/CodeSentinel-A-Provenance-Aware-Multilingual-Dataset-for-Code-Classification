#include<stdio.h>
int main(){int n;scanf("%d",&n);int h[n+1],stk[n+2],top=0;for(int i=0;i<n;i++)scanf("%d",&h[i]);h[n]=0;long long mx=0;for(int i=0;i<=n;i++){while(top>0&&h[stk[top-1]]>h[i]){int ht=h[stk[--top]];int w=top==0?i:i-stk[top-1]-1;long long a=(long long)ht*w;if(a>mx)mx=a;}stk[top++]=i;}printf("%lld\n",mx);}
