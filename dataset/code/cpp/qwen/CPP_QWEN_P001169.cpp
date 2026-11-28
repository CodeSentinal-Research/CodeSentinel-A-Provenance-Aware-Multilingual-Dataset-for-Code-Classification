#include<bits/stdc++.h>
using namespace std;
int main(){int r,c;cin>>r>>c;vector<vector<int>>g(r,vector<int>(c));for(int i=0;i<r;i++)for(int j=0;j<c;j++)cin>>g[i][j];vector<vector<long long>>dp(r,vector<long long>(c,1e18));dp[r-1][c-1]=1;for(int i=r-1;i>=0;i--)for(int j=c-1;j>=0;j--){if(i==r-1&&j==c-1)continue;long long mn=1e18;if(i+1<r)mn=min(mn,dp[i+1][j]);if(j+1<c)mn=min(mn,dp[i][j+1]);dp[i][j]=max(1LL,mn-g[i][j]);}cout<<dp[0][0]<<endl;return 0;}
