#include <iostream>
#include <vector>
#include <set>
using namespace std;
int main(){int n,m1,m2;cin>>n>>m1>>m2;vector<set<int>>g1(n),g2(n);for(int i=0;i<m1;i++){int u,v;cin>>u>>v;g1[u].insert(v);g1[v].insert(u);}for(int i=0;i<m2;i++){int u,v;cin>>u>>v;g2[u].insert(v);g2[v].insert(u);}vector<int>d1(n),d2(n);for(int i=0;i<n;i++){d1[i]=g1[i].size();d2[i]=g2[i].size();}sort(d1.begin(),d1.end());sort(d2.begin(),d2.end());cout<<(d1==d2?"YES":"NO")<<endl;return 0;}
