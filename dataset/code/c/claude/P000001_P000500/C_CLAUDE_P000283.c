#include<stdio.h>
#include<string.h>
int max2(int a,int b){return a>b?a:b;}
int main(){char s1[1001],s2[1001];scanf("%s %s",s1,s2);int m=strlen(s1),n=strlen(s2),dp[m+1][n+1];for(int i=0;i<=m;i++)dp[i][0]=0;for(int j=0;j<=n;j++)dp[0][j]=0;for(int i=1;i<=m;i++)for(int j=1;j<=n;j++)dp[i][j]=s1[i-1]==s2[j-1]?dp[i-1][j-1]+1:max2(dp[i-1][j],dp[i][j-1]);printf("%d\n",dp[m][n]);}
