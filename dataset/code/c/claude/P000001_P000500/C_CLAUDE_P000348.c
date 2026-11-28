#include<stdio.h>
#define MOD 1000000007
int main(){int n;scanf("%d",&n);long long dp[2][3]={};dp[0][0]=1;
for(int i=0;i<n;i++){long long nd[2][3]={};for(int a=0;a<2;a++)for(int l=0;l<3;l++){if(!dp[a][l])continue;nd[a][0]=(nd[a][0]+dp[a][l])%MOD;if(l<2)nd[a][l+1]=(nd[a][l+1]+dp[a][l])%MOD;if(a==0)nd[1][0]=(nd[1][0]+dp[a][l])%MOD;}for(int a=0;a<2;a++)for(int l=0;l<3;l++)dp[a][l]=nd[a][l];}long long res=0;for(int a=0;a<2;a++)for(int l=0;l<3;l++)res=(res+dp[a][l])%MOD;printf("%lld\n",res);}
