#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int bfs(int u,vector<vector<int>>&adj,vector<int>&dist){fill(dist.begin(),dist.end(),-1);queue<int>q;q.push(u);dist[u]=0;int last=u;while(!q.empty()){int v=q.front();q.pop();last=v;for(int w:adj[v])if(dist[w]==-1){dist[w]=dist[v]+1;q.push(w);}}return last;}
int main(){int n;cin>>n;vector<vector<int>>adj(n);for(int i=0;i<n-1;i++){int u,v;cin>>u>>v;adj[u].push_back(v);adj[v].push_back(u);}vector<int>dist(n);int u=bfs(0,adj,dist);int v=bfs(u,adj,dist);int d=dist[v];vector<int>path;int cur=v;while(cur!=-1){path.push_back(cur);for(int p:adj[cur])if(dist[p]==dist[cur]-1){cur=p;break;}}if(d%2==0)cout<<path[d/2]<<endl;else cout<<min(path[d/2],path[d/2+1])<<" "<<max(path[d/2],path[d/2+1])<<endl;return 0;}
