#include <stdio.h>
#include <string.h>
int dp[21][501];
int solve(int e, int f) { if(f<=1) return f; if(e==1) return f; if(dp[e][f]!=-1) return dp[e][f]; int min=2147483647; for(int x=1;x<=f;x++) { int cost=1+(solve(e-1,x-1)>solve(e,f-x)?solve(e-1,x-1):solve(e,f-x)); if(cost<min) min=cost; } return dp[e][f]=min; }
int main() { int e,f; scanf("%d%d",&e,&f); memset(dp,-1,sizeof(dp)); printf("%d\n",solve(e,f)); return 0; }
