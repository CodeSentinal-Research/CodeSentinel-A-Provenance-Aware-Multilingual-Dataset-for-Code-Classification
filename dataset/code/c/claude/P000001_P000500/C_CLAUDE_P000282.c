#include<stdio.h>
#include<string.h>
int main(){char s1[1001],s2[1001];scanf("%s %s",s1,s2);int m=strlen(s1),n=strlen(s2),dp[m+1][n+1],best=0,end=0;for(int i=0;i<=m;i++)dp[i][0]=0;for(int j=0;j<=n;j++)dp[0][j]=0;for(int i=1;i<=m;i++)for(int j=1;j<=n;j++){if(s1[i-1]==s2[j-1]){dp[i][j]=dp[i-1][j-1]+1;if(dp[i][j]>best){best=dp[i][j];end=i;}}else dp[i][j]=0;}char r[best+1];strncpy(r,s1+end-best,best);r[best]=0;printf("%s\n",r);}
