#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main(){string s;cin>>s;int n=s.size(),best=0;vector<int>dp(n,0);for(int i=1;i<n;i++){if(s[i]==")"){if(s[i-1]=="(")dp[i]=(i>=2?dp[i-2]:0)+2;else if(dp[i-1]>0){int j=i-dp[i-1]-1;if(j>=0&&s[j]=="(")dp[i]=dp[i-1]+2+(j>0?dp[j-1]:0);}best=max(best,dp[i]);}}cout<<best<<"\n";}
