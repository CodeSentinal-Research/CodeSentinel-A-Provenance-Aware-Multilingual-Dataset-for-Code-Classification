#include<bits/stdc++.h>
using namespace std;
int main(){int n,m;cin>>n>>m;vector<vector<int>>adj(n),radj(n);for(int i=0;i<m;i++){int u,v;cin>>u>>v;adj[u].push_back(v);radj[v].push_back(u);}vector<int>out(n,0);for(int i=0;i<n;i++)out[i]=adj[i].size();queue<int>q;for(int i=0;i<n;i++)if(out[i]==0)q.push(i);vector<bool>safe(n,false);while(!q.empty()){int u=q.front();q.pop();safe[u]=true;for(int v:radj[u])if(--out[v]==0)q.push(v);}for(int i=0;i<n;i++)if(safe[i])cout<<i<<" ";cout<<endl;return 0;}
