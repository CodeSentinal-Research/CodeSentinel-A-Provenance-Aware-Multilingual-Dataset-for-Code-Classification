#include<bits/stdc++.h>
using namespace std;
int main(){int n;cin>>n;vector<int>a(n);unordered_map<int,int>cnt;int mx=0;for(int i=0;i<n;i++){cin>>a[i];cnt[a[i]]+=a[i];mx=max(mx,a[i]);}vector<long long>dp(mx+1,0);for(int i=1;i<=mx;i++)dp[i]=max(dp[i-1],dp[max(0,i-2)]+cnt[i]);cout<<dp[mx]<<endl;return 0;}
