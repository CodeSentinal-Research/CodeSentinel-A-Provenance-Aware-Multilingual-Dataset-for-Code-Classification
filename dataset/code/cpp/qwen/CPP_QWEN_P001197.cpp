#include<bits/stdc++.h>
using namespace std;
int main(){int n;cin>>n;vector<int>a(n);for(int i=0;i<n;i++)cin>>a[i];unordered_map<int,unordered_map<int,long long>>dp;long long res=0;for(int i=0;i<n;i++)for(int j=0;j<i;j++){int diff=a[i]-a[j];long long cnt=dp[j].count(diff)?dp[j][diff]:0;dp[i][diff]+=cnt+1;if(cnt>0)res+=cnt;}cout<<res<<endl;return 0;}
