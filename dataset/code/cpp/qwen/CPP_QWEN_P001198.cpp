#include<bits/stdc++.h>
using namespace std;
int main(){int r,c;cin>>r>>c;vector<vector<int>>g(r,vector<int>(c));for(int i=0;i<r;i++)for(int j=0;j<c;j++)cin>>g[i][j];vector<vector<int>>dp(r,vector<int>(c,0));int res=0;for(int i=0;i<r;i++)for(int j=0;j<c;j++){if(g[i][j]==1){if(i==0||j==0)dp[i][j]=1;else dp[i][j]=min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]})+1;res+=dp[i][j];}}cout<<res<<endl;return 0;}
