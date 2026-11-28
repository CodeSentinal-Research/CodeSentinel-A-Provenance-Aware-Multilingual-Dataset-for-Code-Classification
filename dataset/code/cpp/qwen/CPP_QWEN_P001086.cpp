#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main(){int n,m,k;cin>>n>>m>>k;vector<vector<int>>adj(n);for(int i=0;i<m;i++){int u,v;cin>>u>>v;adj[u].push_back(v);adj[v].push_back(u);}vector<int>dist(n,-1);queue<int>q;for(int i=0;i<k;i++){int s;cin>>s;if(dist[s]==-1){dist[s]=0;q.push(s);}}while(!q.empty()){int u=q.front();q.pop();for(int v:adj[u])if(dist[v]==-1){dist[v]=dist[u]+1;q.push(v);}}for(int i=0;i<n;i++)cout<<dist[i]<<" ";cout<<endl;return 0;}
