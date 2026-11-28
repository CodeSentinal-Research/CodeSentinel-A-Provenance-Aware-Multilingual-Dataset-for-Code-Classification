#include <stdio.h>
int main(){int n,W;scanf("%d %d",&n,&W);int wt[n],val[n];for(int i=0;i<n;i++)scanf("%d",&wt[i]);for(int i=0;i<n;i++)scanf("%d",&val[i]);long long dp[W+1];for(int j=0;j<=W;j++)dp[j]=0;for(int i=0;i<n;i++)for(int j=W;j>=wt[i];j--){long long t=dp[j-wt[i]]+val[i];if(t>dp[j])dp[j]=t;}printf("%lld\n",dp[W]);return 0;}
