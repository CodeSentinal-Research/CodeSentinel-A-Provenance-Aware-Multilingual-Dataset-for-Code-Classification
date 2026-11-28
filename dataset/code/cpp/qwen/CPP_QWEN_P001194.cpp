#include<bits/stdc++.h>
using namespace std;
int main(){int n,k;cin>>n>>k;vector<int>a(n);for(int i=0;i<n;i++)cin>>a[i];vector<long long>dp(n+1,0);for(int i=1;i<=n;i++){int mx=0;for(int j=1;j<=k&&i-j>=0;j++){mx=max(mx,a[i-j]);dp[i]=max(dp[i],dp[i-j]+mx*(long long)j);}}cout<<dp[n]<<endl;return 0;}
