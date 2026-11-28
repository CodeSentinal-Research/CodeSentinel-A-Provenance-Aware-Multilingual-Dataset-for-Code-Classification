#include <iostream>
#include <vector>
using namespace std;
bool dfs(int u,vector<vector<int>>&adj,vector<int>&vis){vis[u]=1;for(int v:adj[u]){if(!vis[v]){if(dfs(v,adj,vis))return true;}else if(vis[v]==1)return true;}vis[u]=2;return false;}
int main(){int n,m;cin>>n>>m;vector<vector<int>>adj(n+1);for(int i=0;i<m;i++){int u,v;cin>>u>>v;adj[u].push_back(v);}vector<int>vis(n+1,0);bool cyc=false;for(int i=1;i<=n;i++)if(!vis[i]&&dfs(i,adj,vis)){cyc=true;break;}cout<<(cyc?"YES":"NO")<<endl;return 0;}
