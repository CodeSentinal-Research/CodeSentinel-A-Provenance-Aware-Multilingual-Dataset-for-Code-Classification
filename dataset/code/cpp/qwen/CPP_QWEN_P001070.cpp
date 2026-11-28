#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main(){int n,m;cin>>n>>m;vector<vector<int>>adj(n+1);for(int i=0;i<m;i++){int u,v;cin>>u>>v;adj[u].push_back(v);adj[v].push_back(u);}vector<int>col(n+1,-1);bool ok=true;for(int i=1;i<=n;i++){if(col[i]!=-1)continue;queue<int>q;q.push(i);col[i]=0;while(!q.empty()){int u=q.front();q.pop();for(int v:adj[u]){if(col[v]==-1){col[v]=1-col[u];q.push(v);}else if(col[v]==col[u]){ok=false;break;}}if(!ok)break;}if(!ok)break;}}cout<<(ok?"YES":"NO")<<endl;return 0;}
