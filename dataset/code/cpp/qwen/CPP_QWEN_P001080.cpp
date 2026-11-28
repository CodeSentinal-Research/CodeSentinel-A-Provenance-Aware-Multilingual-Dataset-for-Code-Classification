#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int timer=0;vector<int>tin,low;vector<int>aps;
void dfs(int u,int p,vector<vector<int>>&adj){tin[u]=low[u]=++timer;int ch=0;for(int v:adj[u]){if(v==p)continue;if(tin[v]){low[u]=min(low[u],tin[v]);}else{dfs(v,u,adj);low[u]=min(low[u],low[v]);if(low[v]>=tin[u]&&p!=-1)aps.push_back(u);ch++;}}if(p==-1&&ch>1)aps.push_back(u);}
int main(){int n,m;cin>>n>>m;vector<vector<int>>adj(n+1);for(int i=0;i<m;i++){int u,v;cin>>u>>v;adj[u].push_back(v);adj[v].push_back(u);}tin.assign(n+1,0);low.assign(n+1,0);for(int i=1;i<=n;i++)if(!tin[i])dfs(i,-1,adj);sort(aps.begin(),aps.end());aps.erase(unique(aps.begin(),aps.end()),aps.end());if(aps.empty())cout<<"NONE"<<endl;else for(int x:aps)cout<<x<<" ";cout<<endl;return 0;}
