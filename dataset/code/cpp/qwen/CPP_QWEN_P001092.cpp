#include <iostream>
#include <vector>
using namespace std;
vector<int>dep;vector<vector<int>>up;
void dfs(int u,int p,int d,vector<vector<int>>&adj){dep[u]=d;up[u][0]=p;for(int i=1;i<20;i++)up[u][i]=up[up[u][i-1]][i-1];for(int v:adj[u])if(v!=p)dfs(v,u,d+1,adj);}
int main(){int n,q;cin>>n>>q;vector<vector<int>>adj(n),up(n,vector<int>(20));for(int i=0;i<n-1;i++){int u,v;cin>>u>>v;adj[u].push_back(v);adj[v].push_back(u);}dep.resize(n);dfs(0,0,0,adj);while(q--){int u,k;cin>>u>>k;if(dep[u]<k)cout<<-1<<endl;else{for(int i=0;i<20;i++)if((k>>i)&1)u=up[u][i];cout<<u<<endl;}}return 0;}
