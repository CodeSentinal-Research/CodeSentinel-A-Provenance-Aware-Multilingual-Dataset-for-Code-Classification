#include<bits/stdc++.h>
using namespace std;
vector<int>adj[200005];int tin[200005],low[200005],timer=0;vector<pair<int,int>>br;
void dfs(int u,int p){tin[u]=low[u]=++timer;for(int v:adj[u]){if(v==p)continue;if(tin[v]){low[u]=min(low[u],tin[v]);}else{dfs(v,u);low[u]=min(low[u],low[v]);if(low[v]>tin[u])br.push_back({min(u,v),max(u,v)});}}}
int main(){int n,m;cin>>n>>m;for(int i=0;i<m;i++){int u,v;cin>>u>>v;adj[u].push_back(v);adj[v].push_back(u);}for(int i=1;i<=n;i++)if(!tin[i])dfs(i,0);sort(br.begin(),br.end());if(br.empty())cout<<"NONE"<<endl;else for(auto&p:br)cout<<p.first<<" "<<p.second<<endl;return 0;}
