#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){int n,m;cin>>n>>m;vector<vector<int>>adj(n+1);for(int i=0;i<m;i++){int u,v;cin>>u>>v;adj[u].push_back(v);adj[v].push_back(u);}int v;cin>>v;sort(adj[v].begin(),adj[v].end());for(int x:adj[v])cout<<x<<" ";cout<<endl;return 0;}
