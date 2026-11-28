#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int bfs(int u,vector<vector<int>>&adj,vector<int>&dist){fill(dist.begin(),dist.end(),-1);queue<int>q;q.push(u);dist[u]=0;int last=u;while(!q.empty()){int v=q.front();q.pop();last=v;for(int w:adj[v])if(dist[w]==-1){dist[w]=dist[v]+1;q.push(w);}}return last;}
int main(){int n;cin>>n;vector<vector<int>>adj(n);for(int i=0;i<n-1;i++){int u,v;cin>>u>>v;adj[u].push_back(v);adj[v].push_back(u);}vector<int>dist(n);int u=bfs(0,adj,dist);bfs(u,adj,dist);int mx=0;for(int x:dist)mx=max(mx,x);cout<<mx<<endl;return 0;}
