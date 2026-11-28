#include<bits/stdc++.h>
using namespace std;
vector<int>adj[35];int col[35],v,e,m;
bool dfs(int u){if(u==v)return true;for(int c=1;c<=m;c++){bool ok=true;for(int x:adj[u])if(col[x]==c){ok=false;break;}if(ok){col[u]=c;if(dfs(u+1))return true;col[u]=0;}}return false;}
int main(){cin>>v>>e>>m;for(int i=0;i<e;i++){int u,w;cin>>u>>w;adj[u].push_back(w);adj[w].push_back(u);}cout<<(dfs(0)?"YES":"NO")<<endl;return 0;}
