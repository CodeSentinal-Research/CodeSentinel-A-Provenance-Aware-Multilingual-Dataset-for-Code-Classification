#include<bits/stdc++.h>
using namespace std;
int main(){int n;cin>>n;vector<vector<int>>g(n,vector<int>(n));for(int i=0;i<n;i++)for(int j=0;j<n;j++)cin>>g[i][j];vector<int>dp=g[0];for(int i=1;i<n;i++){vector<int>nd(n,1e9);for(int j=0;j<n;j++){if(j>0)nd[j]=min(nd[j],dp[j-1]+g[i][j]);nd[j]=min(nd[j],dp[j]+g[i][j]);if(j<n-1)nd[j]=min(nd[j],dp[j+1]+g[i][j]);}dp=nd;}cout<<*min_element(dp.begin(),dp.end())<<endl;return 0;}
