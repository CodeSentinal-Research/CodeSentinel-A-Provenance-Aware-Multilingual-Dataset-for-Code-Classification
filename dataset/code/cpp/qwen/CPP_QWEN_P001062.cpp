#include <iostream>
#include <vector>
using namespace std;
int main(){int n,m;cin>>n>>m;vector<int>in(n+1,0);for(int i=0;i<m;i++){int u,v;cin>>u>>v;in[v]++;}int c=0;for(int i=1;i<=n;i++)if(in[i]==0)c++;cout<<c<<endl;return 0;}
