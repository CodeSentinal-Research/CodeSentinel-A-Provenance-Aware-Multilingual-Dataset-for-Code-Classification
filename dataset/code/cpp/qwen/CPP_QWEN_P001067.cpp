#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main(){int n,m,s;cin>>n>>m>>s;vector<vector<int>>adj(n+1);for(int i=0;i<m;i++){int u,v;cin>>u>>v;adj[u].push_back(v);adj[v].push_back(u);}vector<bool>vis(n+1,false);queue<int>q;q.push(s);vis[s]=true;int c=0;while(!q.empty()){int u=q.front();q.pop();c++;for(int v:adj[u])if(!vis[v]){vis[v]=true;q.push(v);}}cout<<c<<endl;return 0;}
