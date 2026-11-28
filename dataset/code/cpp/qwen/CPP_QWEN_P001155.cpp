#include<bits/stdc++.h>
using namespace std;
int main(){int n;cin>>n;vector<int>a(n);for(int i=0;i<n;i++)cin>>a[i];vector<vector<long long>>dp(n,vector<long long>(n,0));for(int len=2;len<=n;len++)for(int i=0;i<=n-len;i++){int j=i+len-1;for(int k=i;k<=j;k++){long long left=(k>i?dp[i][k-1]:1);long long right=(k<j?dp[k+1][j]:1);dp[i][j]=max(dp[i][j],left*right*a[k]);}}cout<<dp[0][n-1]<<endl;return 0;}
