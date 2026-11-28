#include<bits/stdc++.h>
using namespace std;
int main(){int n,m,s;cin>>n>>m>>s;vector<vector<pair<int,int>>>adj(n);for(int i=0;i<m;i++){int u,v,w;cin>>u>>v>>w;adj[u].push_back({v,w});}vector<int>dist(n,1e9);dist[s]=0;priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>pq;pq.push({0,s});while(!pq.empty()){auto[d,u]=pq.top();pq.pop();if(d>dist[u])continue;for(auto&[v,w]:adj[u])if(dist[u]+w<dist[v]){dist[v]=dist[u]+w;pq.push({dist[v],v});}}int mx=0;for(int i=0;i<n;i++)mx=max(mx,dist[i]);cout<<(mx==1e9?-1:mx)<<endl;return 0;}
