#include <stdio.h>
#include <string.h>
int main(){char s1[1001],s2[1001];scanf("%s %s",s1,s2);int m=strlen(s1),n=strlen(s2),dp[m+1][n+1];for(int i=0;i<=m;i++)dp[i][0]=i;for(int j=0;j<=n;j++)dp[0][j]=j;for(int i=1;i<=m;i++)for(int j=1;j<=n;j++){if(s1[i-1]==s2[j-1])dp[i][j]=dp[i-1][j-1];else{int a=dp[i-1][j-1],b=dp[i-1][j],c=dp[i][j-1];dp[i][j]=1+(a<b?(a<c?a:c):(b<c?b:c));}}printf("%d\n",dp[m][n]);return 0;}
