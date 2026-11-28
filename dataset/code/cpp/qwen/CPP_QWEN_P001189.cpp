#include<bits/stdc++.h>
using namespace std;
int main(){int n,k;cin>>n>>k;vector<int>a(n);for(int i=0;i<n;i++)cin>>a[i];vector<vector<long long>>dp(2*k+2,vector<long long>(n,-1e18));dp[0][0]=0;for(int i=0;i<=2*k;i++)dp[i][0]=-1e18;for(int i=1;i<=2*k;i+=2)dp[i][0]=-a[0];for(int i=1;i<n;i++)for(int j=0;j<=2*k;j++){dp[j][i]=dp[j][i-1];if(j>0&&dp[j-1][i-1]!=-1e18)dp[j][i]=max(dp[j][i],dp[j-1][i-1]+(j%2==1?-a[i]:a[i]));}long long res=0;for(int i=0;i<=2*k;i+=2)res=max(res,dp[i][n-1]);cout<<res<<endl;return 0;}
