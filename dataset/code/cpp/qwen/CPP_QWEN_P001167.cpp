#include<bits/stdc++.h>
using namespace std;
int main(){int n;cin>>n;vector<vector<int>>c(n,vector<int>(3));for(int i=0;i<n;i++)for(int j=0;j<3;j++)cin>>c[i][j];vector<vector<int>>dp(n,vector<int>(3,0));dp[0]=c[0];for(int i=1;i<n;i++)for(int j=0;j<3;j++)for(int k=0;k<3;k++)if(j!=k)dp[i][j]=max(dp[i][j],dp[i-1][k]+c[i][j]);cout<<max({dp[n-1][0],dp[n-1][1],dp[n-1][2]})<<endl;return 0;}
