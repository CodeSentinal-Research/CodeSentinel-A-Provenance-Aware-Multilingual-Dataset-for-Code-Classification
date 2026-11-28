#include<stdio.h>
int main(){int n,m;scanf("%d %d",&n,&m);
long long g[n][m],p[n+1][m+1];
for(int i=0;i<n;i++)for(int j=0;j<m;j++)scanf("%lld",&g[i][j]);
for(int i=0;i<=n;i++)for(int j=0;j<=m;j++)p[i][j]=0;
for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)p[i][j]=g[i-1][j-1]+p[i-1][j]+p[i][j-1]-p[i-1][j-1];
int q;scanf("%d",&q);while(q--){int r1,c1,r2,c2;scanf("%d %d %d %d",&r1,&c1,&r2,&c2);
    printf("%lld\n",p[r2+1][c2+1]-p[r1][c2+1]-p[r2+1][c1]+p[r1][c1]);}
}
