#include<bits/stdc++.h>
using namespace std;
int main(){string s;cin>>s;int n=s.size();vector<vector<int>>dp(n,vector<int>(n,0));for(int i=0;i<n;i++)dp[i][i]=1;for(int len=2;len<=n;len++)for(int i=0;i<=n-len;i++){int j=i+len-1;dp[i][j]=(s[i]==s[j])?dp[i+1][j-1]+2:max(dp[i+1][j],dp[i][j-1]);}cout<<dp[0][n-1]<<endl;return 0;}
