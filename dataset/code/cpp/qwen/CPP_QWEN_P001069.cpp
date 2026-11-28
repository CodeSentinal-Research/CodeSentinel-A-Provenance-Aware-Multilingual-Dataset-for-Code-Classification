#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main(){int n,m,s;cin>>n>>m>>s;vector<vector<pair<int,int>>>adj(n+1);vector<int>in(n+1,0);for(int i=0;i<m;i++){int u,v,w;cin>>u>>v>>w;adj[u].push_back({v,w});in[v]++;}queue<int>q;for(int i=1;i<=n;i++)if(in[i]==0)q.push(i);vector<long long>dist(n+1,1e18);dist[s]=0;while(!q.empty()){int u=q.front();q.pop();for(auto&p:adj[u]){int v=p.first,w=p.second;if(dist[u]+w<dist[v]){dist[v]=dist[u]+w;if(--in[v]==0)q.push(v);}}}for(int i=1;i<=n;i++)cout<<(dist[i]==1e18?-1:dist[i])<<" ";cout<<endl;return 0;}
