#include <iostream>
#include <set>
using namespace std;
int main(){int n,m,q;cin>>n>>m>>q;set<pair<int,int>>edges;for(int i=0;i<m;i++){int u,v;cin>>u>>v;edges.insert({u,v});}while(q--){int u,v;cin>>u>>v;cout<<(edges.count({u,v})?"YES":"NO")<<endl;}return 0;}
