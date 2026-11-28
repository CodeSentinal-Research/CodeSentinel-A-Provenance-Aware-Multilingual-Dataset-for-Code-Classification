#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main(){string s1,s2;cin>>s1>>s2;int m=s1.size(),n=s2.size(),best=0,end=0;vector<vector<int>>dp(m+1,vector<int>(n+1,0));for(int i=1;i<=m;i++)for(int j=1;j<=n;j++){if(s1[i-1]==s2[j-1]){dp[i][j]=dp[i-1][j-1]+1;if(dp[i][j]>best){best=dp[i][j];end=i;}}else dp[i][j]=0;}cout<<s1.substr(end-best,best)<<"\n";}
