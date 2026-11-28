#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main(){int n,m,s;cin>>n>>m>>s;vector<vector<pair<long long,int>>>adj(n+1);for(int i=0;i<m;i++){int u,v;long long w;cin>>u>>v>>w;adj[u].push_back({w,v});}vector<long long>dist(n+1,1e18);priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<>>pq;dist[s]=0;pq.push({0,s});while(!pq.empty()){auto[d,u]=pq.top();pq.pop();if(d>dist[u])continue;for(auto&p:adj[u]){int v=p.second;long long w=p.first;if(dist[u]+w<dist[v]){dist[v]=dist[u]+w;pq.push({dist[v],v});}}}for(int i=1;i<=n;i++)cout<<dist[i]<<" ";cout<<endl;return 0;}
