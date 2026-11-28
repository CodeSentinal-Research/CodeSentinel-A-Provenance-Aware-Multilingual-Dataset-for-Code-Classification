#include <iostream>
#include <vector>
using namespace std;
vector<int>match;vector<vector<int>>adj;vector<bool>vis;
bool dfs(int u){for(int v:adj[u])if(!vis[v]){vis[v]=true;if(match[v]==-1||dfs(match[v])){match[v]=u;return true;}}return false;}
int main(){int l,r,m;cin>>l>>r>>m;adj.resize(l);for(int i=0;i<m;i++){int u,v;cin>>u>>v;adj[u].push_back(v);}match.assign(r,-1);int res=0;for(int i=0;i<l;i++){vis.assign(r,false);if(dfs(i))res++;}cout<<res<<endl;return 0;}
