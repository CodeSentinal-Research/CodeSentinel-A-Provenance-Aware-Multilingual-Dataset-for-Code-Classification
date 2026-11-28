#include<stdio.h>
long long largestHist(int*h,int n){int stk[n+2],top=0;h[n]=0;long long mx=0;for(int i=0;i<=n;i++){while(top>0&&h[stk[top-1]]>h[i]){int ht=h[stk[--top]];int w=top==0?i:i-stk[top-1]-1;long long a=(long long)ht*w;if(a>mx)mx=a;}stk[top++]=i;}return mx;}
int main(){int r,c;scanf("%d %d",&r,&c);char mat[r][c+1];int h[c+1];for(int j=0;j<=c;j++)h[j]=0;long long ans=0;for(int i=0;i<r;i++){for(int j=0;j<c;j++){scanf("%s",&mat[i][j]);h[j]=mat[i][j]=='1'?h[j]+1:0;}long long v=largestHist(h,c);if(v>ans)ans=v;}printf("%lld\n",ans);}
