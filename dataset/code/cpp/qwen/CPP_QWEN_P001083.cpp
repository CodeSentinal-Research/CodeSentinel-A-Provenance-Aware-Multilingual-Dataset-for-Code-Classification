#include <iostream>
#include <vector>
using namespace std;
int n,m;vector<vector<int>>adj;vector<vector<int>>dp;
int dfs(int u,int mask){if(mask==(1<<n)-1)return 1;if(dp[u][mask]!=-1)return dp[u][mask];int res=0;for(int v:adj[u])if(!(mask&(1<<v)))res+=dfs(v,mask|(1<<v));return dp[u][mask]=res;}
int main(){cin>>n>>m;adj.resize(n);for(int i=0;i<m;i++){int u,v;cin>>u>>v;adj[u].push_back(v);adj[v].push_back(u);}dp.assign(n,vector<int>(1<<n,-1));int res=0;for(int i=0;i<n;i++)res+=dfs(i,1<<i);cout<<(res>0?"YES":"NO")<<endl;return 0;}
