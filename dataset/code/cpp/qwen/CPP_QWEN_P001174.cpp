#include<bits/stdc++.h>
using namespace std;
int main(){int n;cin>>n;vector<vector<int>>t(n);for(int i=0;i<n;i++){t[i].resize(i+1);for(int j=0;j<=i;j++)cin>>t[i][j];}vector<int>dp=t[n-1];for(int i=n-2;i>=0;i--)for(int j=0;j<=i;j++)dp[j]=t[i][j]+min(dp[j],dp[j+1]);cout<<dp[0]<<endl;return 0;}
