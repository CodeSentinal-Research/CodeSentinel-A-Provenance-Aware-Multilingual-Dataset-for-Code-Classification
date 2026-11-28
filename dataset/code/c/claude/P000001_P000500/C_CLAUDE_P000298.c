#include<stdio.h>
#include<string.h>
int main(){char s[100001];scanf("%s",s);int n=strlen(s),dp[n],best=0;for(int i=0;i<n;i++)dp[i]=0;for(int i=1;i<n;i++){if(s[i]==")"){if(s[i-1]=="(")dp[i]=(i>=2?dp[i-2]:0)+2;else if(dp[i-1]>0){int j=i-dp[i-1]-1;if(j>=0&&s[j]=="(")dp[i]=dp[i-1]+2+(j>0?dp[j-1]:0);}if(dp[i]>best)best=dp[i];}}printf("%d\n",best);}
