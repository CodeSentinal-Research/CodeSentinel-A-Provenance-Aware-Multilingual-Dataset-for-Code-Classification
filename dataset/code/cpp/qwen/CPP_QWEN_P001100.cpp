#include <iostream>
#include <vector>
#include <string>
using namespace std;
struct DSU{vector<int>p;DSU(int n){p.resize(n);for(int i=0;i<n;i++)p[i]=i;}int find(int x){return p[x]==x?x:p[x]=find(p[x]);}void unite(int x,int y){p[find(x)]=find(y);}};
int main(){int n,q;cin>>n>>q;DSU dsu(n);while(q--){string op;cin>>op;if(op=="ADD"){int u,v;cin>>u>>v;dsu.unite(u,v);}else{int u,v;cin>>u>>v;cout<<(dsu.find(u)==dsu.find(v)?"YES":"NO")<<endl;}}return 0;}
