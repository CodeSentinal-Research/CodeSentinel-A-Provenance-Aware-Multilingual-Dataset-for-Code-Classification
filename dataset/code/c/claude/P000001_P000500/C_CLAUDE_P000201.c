#include <stdio.h>
int main(){int n;scanf("%d",&n);int a[n],dp[n];for(int i=0;i<n;i++)scanf("%d",&a[i]);for(int i=0;i<n;i++)dp[i]=a[i];for(int i=1;i<n;i++)for(int j=0;j<i;j++)if(a[j]<a[i]&&dp[j]+a[i]>dp[i])dp[i]=dp[j]+a[i];int ans=dp[0];for(int i=1;i<n;i++)if(dp[i]>ans)ans=dp[i];printf("%d\n",ans);return 0;}
