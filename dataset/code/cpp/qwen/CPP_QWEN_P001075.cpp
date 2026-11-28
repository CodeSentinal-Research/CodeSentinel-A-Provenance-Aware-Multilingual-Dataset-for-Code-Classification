#include <iostream>
#include <vector>
using namespace std;
int main(){int n,m,s;cin>>n>>m>>s;vector<tuple<int,int,long long>>edges(m);vector<long long>dist(n+1,1e18);dist[s]=0;for(int i=0;i<m;i++){int u,v;long long w;cin>>u>>v>>w;edges[i]={u,v,w};}for(int i=0;i<n-1;i++)for(auto&[u,v,w]:edges)if(dist[u]!=1e18&&dist[u]+w<dist[v])dist[v]=dist[u]+w;bool neg=false;for(auto&[u,v,w]:edges)if(dist[u]!=1e18&&dist[u]+w<dist[v])neg=true;cout<<(neg?"NEGATIVE CYCLE":"OK")<<endl;return 0;}
