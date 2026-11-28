#include<bits/stdc++.h>
using namespace std;
int main(){int e,f;cin>>e>>f;vector<vector<int>>dp(e+1,vector<int>(f+1,0));for(int i=1;i<=e;i++)dp[i][1]=1;for(int j=1;j<=f;j++)dp[1][j]=j;for(int i=2;i<=e;i++)for(int j=2;j<=f;j++){dp[i][j]=1e9;for(int k=1;k<=j;k++)dp[i][j]=min(dp[i][j],1+max(dp[i-1][k-1],dp[i][j-k]));}cout<<dp[e][f]<<endl;return 0;}
