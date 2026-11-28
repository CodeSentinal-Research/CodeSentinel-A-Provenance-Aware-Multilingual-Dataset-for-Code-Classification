#include<bits/stdc++.h>
using namespace std;
int main(){int n,m;cin>>n>>m;vector<vector<int>>adj(n);vector<int>in(n,0);for(int i=0;i<m;i++){int u,v;cin>>u>>v;adj[u].push_back(v);in[v]++;}queue<int>q;for(int i=0;i<n;i++)if(in[i]==0)q.push(i);int cnt=0;while(!q.empty()){int u=q.front();q.pop();cnt++;for(int v:adj[u])if(--in[v]==0)q.push(v);}cout<<(cnt==n?"YES":"NO")<<endl;return 0;}
