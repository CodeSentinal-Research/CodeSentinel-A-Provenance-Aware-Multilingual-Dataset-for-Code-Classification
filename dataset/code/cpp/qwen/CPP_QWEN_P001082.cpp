#include <iostream>
#include <vector>
using namespace std;
int main(){int n,m;cin>>n>>m;vector<int>deg(n+1,0);for(int i=0;i<m;i++){int u,v;cin>>u>>v;deg[u]++;deg[v]++;}int odd=0;for(int i=1;i<=n;i++)if(deg[i]%2!=0)odd++;cout<<(odd==0||odd==2?"POSSIBLE":"IMPOSSIBLE")<<endl;return 0;}
