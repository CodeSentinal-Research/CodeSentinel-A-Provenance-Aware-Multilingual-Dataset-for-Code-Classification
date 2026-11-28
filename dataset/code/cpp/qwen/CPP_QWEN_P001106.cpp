#include<bits/stdc++.h>
using namespace std;
int main(){int n,m;cin>>n>>m;vector<vector<int>>adj(n);vector<int>in(n,0);for(int i=0;i<m;i++){int u,v;cin>>u>>v;adj[u].push_back(v);in[v]++;}queue<int>q;for(int i=0;i<n;i++)if(in[i]==0)q.push(i);vector<int>res;while(!q.empty()){int u=q.front();q.pop();res.push_back(u);for(int v:adj[u])if(--in[v]==0)q.push(v);}if(res.size()==n){for(int x:res)cout<<x<<" ";cout<<endl;}else cout<<"IMPOSSIBLE"<<endl;return 0;}
