#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct DSU{vector<int>p;DSU(int n){p.resize(n);for(int i=0;i<n;i++)p[i]=i;}int find(int x){return p[x]==x?x:p[x]=find(p[x]);}bool unite(int x,int y){x=find(x);y=find(y);if(x==y)return false;p[x]=y;return true;}};
int main(){int n,m;cin>>n>>m;vector<tuple<long long,int,int>>edges(m);for(int i=0;i<m;i++){int u,v;long long w;cin>>u>>v>>w;edges[i]={w,u,v};}sort(edges.begin(),edges.end());DSU dsu(n+1);long long res=0;for(auto&[w,u,v]:edges)if(dsu.unite(u,v))res+=w;cout<<res<<endl;return 0;}
