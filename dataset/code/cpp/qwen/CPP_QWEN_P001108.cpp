#include<bits/stdc++.h>
using namespace std;
int main(){int n,m,q;cin>>n>>m>>q;vector<vector<int>>adj(n);for(int i=0;i<m;i++){int u,v;cin>>u>>v;adj[u].push_back(v);}while(q--){int u,v;cin>>u>>v;vector<bool>vis(n,false);queue<int>qu;qu.push(u);vis[u]=true;bool ok=false;while(!qu.empty()){int x=qu.front();qu.pop();if(x==v){ok=true;break;}for(int y:adj[x])if(!vis[y]){vis[y]=true;qu.push(y);}}cout<<(ok?"YES":"NO")<<endl;}return 0;}
