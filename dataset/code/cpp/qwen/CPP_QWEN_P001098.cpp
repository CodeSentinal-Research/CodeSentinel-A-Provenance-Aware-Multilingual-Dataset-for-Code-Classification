#include <iostream>
#include <vector>
using namespace std;
struct DSU{vector<int>p;int c;DSU(int n){p.resize(n);c=n;for(int i=0;i<n;i++)p[i]=i;}int find(int x){return p[x]==x?x:p[x]=find(p[x]);}void unite(int x,int y){x=find(x);y=find(y);if(x!=y){p[x]=y;c--;}}};
int main(){int n,m;cin>>n>>m;DSU dsu(n);for(int i=0;i<m;i++){int u,v;cin>>u>>v;dsu.unite(u,v);}cout<<dsu.c<<endl;return 0;}
