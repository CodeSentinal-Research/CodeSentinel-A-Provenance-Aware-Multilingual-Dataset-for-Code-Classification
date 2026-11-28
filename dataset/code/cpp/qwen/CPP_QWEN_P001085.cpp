#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main(){int n,m,s,t;cin>>n>>m>>s>>t;vector<vector<int>>adj(n);vector<int>in(n,0);for(int i=0;i<m;i++){int u,v;cin>>u>>v;adj[u].push_back(v);in[v]++;}vector<long long>dp(n,0);dp[s]=1;queue<int>q;for(int i=0;i<n;i++)if(in[i]==0)q.push(i);while(!q.empty()){int u=q.front();q.pop();for(int v:adj[u]){dp[v]+=dp[u];if(--in[v]==0)q.push(v);}}cout<<dp[t]<<endl;return 0;}
