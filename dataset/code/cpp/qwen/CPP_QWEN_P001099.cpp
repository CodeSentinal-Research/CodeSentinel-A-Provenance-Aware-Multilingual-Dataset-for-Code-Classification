#include <iostream>
#include <vector>
using namespace std;
struct DSU{vector<int>p;DSU(int n){p.resize(n);for(int i=0;i<n;i++)p[i]=i;}int find(int x){return p[x]==x?x:p[x]=find(p[x]);}bool unite(int x,int y){x=find(x);y=find(y);if(x==y)return false;p[x]=y;return true;}};
int main(){int n,m;cin>>n>>m;DSU dsu(n);bool cyc=false;for(int i=0;i<m;i++){int u,v;cin>>u>>v;if(!dsu.unite(u,v))cyc=true;}cout<<(cyc?"YES":"NO")<<endl;return 0;}
