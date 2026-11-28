#include<bits/stdc++.h>
using namespace std;
int main(){int n;cin>>n;vector<int>p(n);for(int i=0;i<n;i++)cin>>p[i];vector<int>dp(n+1,0);for(int i=1;i<=n;i++)for(int j=1;j<=i;j++)dp[i]=max(dp[i],dp[i-j]+p[j-1]);cout<<dp[n]<<endl;return 0;}
