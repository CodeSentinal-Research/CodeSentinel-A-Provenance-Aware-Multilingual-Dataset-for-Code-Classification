#include <stdio.h>
#include <string.h>
int dp[100][100];
int solve(int *freq, int i, int j, int sum) { if(i>j) return 0; if(dp[i][j]!=-1) return dp[i][j]; int min=2147483647; for(int r=i;r<=j;r++) { int cost=solve(freq,i,r-1,sum)+solve(freq,r+1,j,sum)+sum-freq[r]; if(cost<min) min=cost; } return dp[i][j]=min; }
int main() { int n; scanf("%d",&n); int keys[n], freq[n]; int sum=0; for(int i=0;i<n;i++) { scanf("%d",&keys[i]); } for(int i=0;i<n;i++) { scanf("%d",&freq[i]); sum+=freq[i]; } memset(dp,-1,sizeof(dp)); printf("%d\n",solve(freq,0,n-1,sum)); return 0; }
