#include <iostream>
#include <vector>
using namespace std;
vector<int>dep,par;vector<vector<int>>up;
void dfs(int u,int p,int d,vector<vector<int>>&adj){par[u]=p;dep[u]=d;up[u][0]=p;for(int i=1;i<20;i++)up[u][i]=up[up[u][i-1]][i-1];for(int v:adj[u])if(v!=p)dfs(v,u,d+1,adj);}
int lca(int u,int v){if(dep[u]<dep[v])swap(u,v);int diff=dep[u]-dep[v];for(int i=0;i<20;i++)if((diff>>i)&1)u=up[u][i];if(u==v)return u;for(int i=19;i>=0;i--)if(up[u][i]!=up[v][i]){u=up[u][i];v=up[v][i];}return up[u][0];}
int main(){int n,q;cin>>n>>q;vector<vector<int>>adj(n),up(n,vector<int>(20));for(int i=0;i<n-1;i++){int u,v;cin>>u>>v;adj[u].push_back(v);adj[v].push_back(u);}dep.resize(n);par.resize(n);dfs(0,0,0,adj);while(q--){int u,v;cin>>u>>v;cout<<lca(u,v)<<endl;}return 0;}
