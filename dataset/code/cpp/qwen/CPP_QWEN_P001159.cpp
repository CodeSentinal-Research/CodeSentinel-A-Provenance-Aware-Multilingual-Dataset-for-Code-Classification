#include<bits/stdc++.h>
using namespace std;
int main(){string s;cin>>s;int n=s.size();vector<long long>dp(n+1,0);dp[0]=1;if(s[0]!='0')dp[1]=1;for(int i=2;i<=n;i++){if(s[i-1]!='0')dp[i]+=dp[i-1];int v=(s[i-2]-'0')*10+(s[i-1]-'0');if(v>=10&&v<=26)dp[i]+=dp[i-2];}cout<<dp[n]<<endl;return 0;}
