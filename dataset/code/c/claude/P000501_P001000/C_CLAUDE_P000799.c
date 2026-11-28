#include<stdio.h>
int main(){int n,m;scanf("%d %d",&n,&m);
long long g[n][m],p[n+1][m+1];
for(int i=0;i<n;i++)for(int j=0;j<m;j++)scanf("%lld",&g[i][j]);
for(int i=0;i<=n;i++)for(int j=0;j<=m;j++)p[i][j]=0;
for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)p[i][j]=g[i-1][j-1]+p[i-1][j]+p[i][j-1]-p[i-1][j-1];
for(int i=1;i<=n;i++){for(int j=1;j<=m;j++)printf("%lld%c",p[i][j],j<m?' ':'\n');}}
