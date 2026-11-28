#include <iostream>
#include <vector>
using namespace std;
void dfs(int u,vector<vector<int>>&adj,vector<bool>&vis){vis[u]=true;for(int v:adj[u])if(!vis[v])dfs(v,adj,vis);}
int main(){int n,m;cin>>n>>m;vector<vector<int>>adj(n+1),radj(n+1);for(int i=0;i<m;i++){int u,v;cin>>u>>v;adj[u].push_back(v);radj[v].push_back(u);}int last=0;vector<bool>vis(n+1,false);for(int i=1;i<=n;i++)if(!vis[i]){dfs(i,adj,vis);last=i;}fill(vis.begin(),vis.end(),false);dfs(last,radj,vis);bool ok=true;for(int i=1;i<=n;i++)if(!vis[i]){ok=false;break;}cout<<(ok?last:-1)<<endl;return 0;}
