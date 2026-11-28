#include <iostream>
#include <vector>
using namespace std;
int main(){int n,m;cin>>n>>m;vector<vector<int>>adj(n+1);vector<int>deg(n+1,0);for(int i=0;i<m;i++){int u,v;cin>>u>>v;adj[u].push_back(v);adj[v].push_back(u);deg[u]++;deg[v]++;}bool ok=true;for(int i=1;i<=n;i++)if(deg[i]%2!=0){ok=false;break;}cout<<(ok?"POSSIBLE":"IMPOSSIBLE")<<endl;return 0;}
