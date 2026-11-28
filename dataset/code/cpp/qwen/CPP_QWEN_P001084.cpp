#include <iostream>
#include <vector>
using namespace std;
int n,m;vector<vector<int>>adj;vector<vector<int>>dp;
int dfs(int u,int mask,int start){if(mask==(1<<n)-1){for(int v:adj[u])if(v==start)return 1;return 0;}if(dp[u][mask]!=-1)return dp[u][mask];int res=0;for(int v:adj[u])if(!(mask&(1<<v)))res+=dfs(v,mask|(1<<v),start);return dp[u][mask]=res;}
int main(){cin>>n>>m;adj.resize(n);for(int i=0;i<m;i++){int u,v;cin>>u>>v;adj[u].push_back(v);adj[v].push_back(u);}dp.assign(n,vector<int>(1<<n,-1));bool ok=false;for(int i=0;i<n;i++)if(dfs(i,1<<i,i)){ok=true;break;}cout<<(ok?"YES":"NO")<<endl;return 0;}
