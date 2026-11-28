#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int timer=0;vector<int>tin,low;vector<pair<int,int>>bridges;
void dfs(int u,int p,vector<vector<int>>&adj){tin[u]=low[u]=++timer;for(int v:adj[u]){if(v==p)continue;if(tin[v]){low[u]=min(low[u],tin[v]);}else{dfs(v,u,adj);low[u]=min(low[u],low[v]);if(low[v]>tin[u])bridges.push_back({min(u,v),max(u,v)});}}}
int main(){int n,m;cin>>n>>m;vector<vector<int>>adj(n+1);for(int i=0;i<m;i++){int u,v;cin>>u>>v;adj[u].push_back(v);adj[v].push_back(u);}tin.assign(n+1,0);low.assign(n+1,0);for(int i=1;i<=n;i++)if(!tin[i])dfs(i,0,adj);sort(bridges.begin(),bridges.end());if(bridges.empty())cout<<"NONE"<<endl;else for(auto&p:bridges)cout<<p.first<<" "<<p.second<<endl;return 0;}
