#include<bits/stdc++.h>
using namespace std;
int main(){int r,c;cin>>r>>c;vector<vector<int>>g(r,vector<int>(c));for(int i=0;i<r;i++)for(int j=0;j<c;j++)cin>>g[i][j];vector<vector<long long>>dp(r,vector<long long>(c,1e18));dp[0][0]=g[0][0];for(int i=0;i<r;i++)for(int j=0;j<c;j++){if(i>0)dp[i][j]=min(dp[i][j],dp[i-1][j]+g[i][j]);if(j>0)dp[i][j]=min(dp[i][j],dp[i][j-1]+g[i][j]);}cout<<dp[r-1][c-1]<<endl;return 0;}
