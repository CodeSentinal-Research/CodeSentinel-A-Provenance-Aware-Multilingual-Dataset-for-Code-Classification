#include <stdio.h>
#include <string.h>
int dp[100][100];
int solve(int *d, int i, int j) { if(i==j) return 0; if(dp[i][j]!=-1) return dp[i][j]; int min=2147483647; for(int k=i;k<j;k++) { int cost=solve(d,i,k)+solve(d,k+1,j)+d[i-1]*d[k]*d[j]; if(cost<min) min=cost; } return dp[i][j]=min; }
int main() { int n; scanf("%d",&n); int d[n]; for(int i=0;i<n;i++) scanf("%d",&d[i]); memset(dp,-1,sizeof(dp)); printf("%d\n",solve(d,1,n-1)); return 0; }
