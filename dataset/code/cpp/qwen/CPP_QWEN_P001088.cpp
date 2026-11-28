#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main(){int n,m,s,k;cin>>n>>m>>s>>k;vector<vector<int>>adj(n);for(int i=0;i<m;i++){int u,v;cin>>u>>v;adj[u].push_back(v);adj[v].push_back(u);}vector<int>dist(n,-1);queue<int>q;q.push(s);dist[s]=0;int c=0;while(!q.empty()){int u=q.front();q.pop();if(dist[u]==k){c++;continue;}if(dist[u]<k)for(int v:adj[u])if(dist[v]==-1){dist[v]=dist[u]+1;q.push(v);}}cout<<c<<endl;return 0;}
