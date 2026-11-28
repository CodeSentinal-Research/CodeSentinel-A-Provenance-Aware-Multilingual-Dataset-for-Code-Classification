#include <stdio.h>
#include <limits.h>
int main(){int n,amt;scanf("%d %d",&n,&amt);int c[n];for(int i=0;i<n;i++)scanf("%d",&c[i]);int dp[amt+1];dp[0]=0;for(int i=1;i<=amt;i++)dp[i]=INT_MAX;for(int i=1;i<=amt;i++)for(int j=0;j<n;j++)if(c[j]<=i&&dp[i-c[j]]!=INT_MAX){int t=dp[i-c[j]]+1;if(t<dp[i])dp[i]=t;}printf("%d\n",dp[amt]==INT_MAX?-1:dp[amt]);return 0;}
