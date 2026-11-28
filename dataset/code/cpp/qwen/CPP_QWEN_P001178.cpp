#include<bits/stdc++.h>
using namespace std;
int main(){int r,c;cin>>r>>c;vector<vector<int>>g(r,vector<int>(c));for(int i=0;i<r;i++)for(int j=0;j<c;j++)cin>>g[i][j];vector<vector<long long>>dp(r,vector<long long>(c,0));for(int j=0;j<c;j++)dp[0][j]=g[0][j];for(int i=1;i<r;i++)for(int j=0;j<c;j++){dp[i][j]=dp[i-1][j];if(j>0)dp[i][j]=max(dp[i][j],dp[i-1][j-1]);if(j<c-1)dp[i][j]=max(dp[i][j],dp[i-1][j+1]);dp[i][j]+=g[i][j];}long long mx=0;for(int j=0;j<c;j++)mx=max(mx,dp[r-1][j]);cout<<mx<<endl;return 0;}
