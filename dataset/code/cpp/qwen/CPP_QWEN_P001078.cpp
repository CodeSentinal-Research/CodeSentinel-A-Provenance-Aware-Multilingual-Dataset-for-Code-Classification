#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main(){int n,m;cin>>n>>m;vector<vector<pair<int,long long>>>adj(n+1);for(int i=0;i<m;i++){int u,v;long long w;cin>>u>>v>>w;adj[u].push_back({v,w});adj[v].push_back({u,w});}priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<>>pq;vector<bool>vis(n+1,false);pq.push({0,1});long long res=0;while(!pq.empty()){auto[w,u]=pq.top();pq.pop();if(vis[u])continue;vis[u]=true;res+=w;for(auto&p:adj[u])if(!vis[p.first])pq.push({p.second,p.first});}cout<<res<<endl;return 0;}
