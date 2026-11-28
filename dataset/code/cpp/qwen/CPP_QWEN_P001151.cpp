#include<bits/stdc++.h>
using namespace std;
int main(){string s;cin>>s;int n=s.size();vector<vector<bool>>dp(n,vector<bool>(n,false));int st=0,mx=1;for(int i=0;i<n;i++)dp[i][i]=true;for(int len=2;len<=n;len++)for(int i=0;i<=n-len;i++){int j=i+len-1;if(len==2)dp[i][j]=(s[i]==s[j]);else dp[i][j]=(s[i]==s[j]&&dp[i+1][j-1]);if(dp[i][j]&&len>mx){mx=len;st=i;}}cout<<s.substr(st,mx)<<endl;return 0;}
