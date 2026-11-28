#include<bits/stdc++.h>
using namespace std;
int main(){int n,m;cin>>n>>m;vector<vector<int>>adj(n);for(int i=0;i<m;i++){int u,v;cin>>u>>v;adj[u].push_back(v);adj[v].push_back(u);}vector<int>col(n);for(int i=0;i<n;i++)cin>>col[i];bool ok=true;for(int i=0;i<n;i++)for(int j:adj[i])if(col[i]==col[j])ok=false;cout<<(ok?"VALID":"INVALID")<<endl;return 0;}
