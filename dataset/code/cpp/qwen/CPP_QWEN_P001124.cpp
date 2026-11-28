#include<bits/stdc++.h>
using namespace std;
int main(){int n,m,s,d,k;cin>>n>>m>>s>>d>>k;vector<vector<pair<int,int>>>adj(n);for(int i=0;i<m;i++){int u,v,w;cin>>u>>v>>w;adj[u].push_back({v,w});}vector<vector<int>>dist(n,vector<int>(k+2,1e9));dist[s][0]=0;queue<pair<int,int>>q;q.push({s,0});while(!q.empty()){auto[u,st]=q.front();q.pop();if(st>k)continue;for(auto&[v,w]:adj[u]){if(st+1<=k+1&&dist[u][st]+w<dist[v][st+1]){dist[v][st+1]=dist[u][st]+w;q.push({v,st+1});}}}int ans=1e9;for(int i=0;i<=k+1;i++)ans=min(ans,dist[d][i]);cout<<(ans==1e9?-1:ans)<<endl;return 0;}
