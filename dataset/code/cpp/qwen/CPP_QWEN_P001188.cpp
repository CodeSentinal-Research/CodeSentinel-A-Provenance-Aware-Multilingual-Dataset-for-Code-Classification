#include<bits/stdc++.h>
using namespace std;
int main(){int n;cin>>n;vector<int>a(n);for(int i=0;i<n;i++)cin>>a[i];vector<vector<long long>>dp(5,vector<long long>(n,0));dp[1][0]=-a[0];dp[3][0]=-1e18;for(int i=1;i<n;i++){dp[0][i]=max(dp[0][i-1],dp[1][i-1]);dp[1][i]=max(dp[1][i-1],dp[2][i-1]-a[i]);dp[2][i]=max(dp[2][i-1],dp[3][i-1]+a[i]);dp[3][i]=max(dp[3][i-1],dp[4][i-1]-a[i]);dp[4][i]=max(dp[4][i-1],dp[3][i-1]+a[i]);}cout<<max({dp[0][n-1],dp[2][n-1],dp[4][n-1]})<<endl;return 0;}
