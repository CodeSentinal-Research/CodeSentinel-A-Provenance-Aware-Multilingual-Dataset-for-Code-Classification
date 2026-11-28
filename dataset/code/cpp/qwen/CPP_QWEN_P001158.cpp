#include<bits/stdc++.h>
using namespace std;
int main(){int n;cin>>n;if(n==2){cout<<1<<endl;return 0;}if(n==3){cout<<2<<endl;return 0;}vector<long long>dp(n+1,0);dp[1]=1;dp[2]=1;dp[3]=2;for(int i=4;i<=n;i++)dp[i]=max({dp[i-1],dp[i-2]*(i-2),dp[i-3]*(i-3)*2});cout<<dp[n]<<endl;return 0;}
