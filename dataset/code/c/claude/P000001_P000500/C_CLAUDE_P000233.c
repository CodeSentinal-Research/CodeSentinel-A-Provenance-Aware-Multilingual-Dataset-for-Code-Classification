#include<stdio.h>
int maxHist(int*h,int n){int stack[n+1],top=-1,mx=0;h[n]=0;for(int i=0;i<=n;i++){while(top>=0&&h[stack[top]]>=h[i]){int ht=h[stack[top--]];int w=top<0?i:i-stack[top]-1;int a=ht*w;if(a>mx)mx=a;}stack[++top]=i;}return mx;}
int main(){int r,c;scanf("%d %d",&r,&c);int h[c+1];for(int j=0;j<=c;j++)h[j]=0;int ans=0;for(int i=0;i<r;i++){for(int j=0;j<c;j++){int x;scanf("%d",&x);h[j]=x?h[j]+1:0;}int v=maxHist(h,c);if(v>ans)ans=v;}printf("%d\n",ans);}
