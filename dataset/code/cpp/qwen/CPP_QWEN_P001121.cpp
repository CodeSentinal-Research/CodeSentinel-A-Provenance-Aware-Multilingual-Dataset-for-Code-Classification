#include<bits/stdc++.h>
using namespace std;
int main(){int n;cin>>n;vector<vector<int>>adj(n);vector<int>in(n,0);for(int i=0;i<n-1;i++){int u,v;cin>>u>>v;adj[u].push_back(v);adj[v].push_back(u);in[u]++;in[v]++;}queue<int>q;for(int i=0;i<n;i++)if(in[i]==1)q.push(i);while(n>2){int sz=q.size();n-=sz;for(int i=0;i<sz;i++){int u=q.front();q.pop();for(int v:adj[u])if(--in[v]==1)q.push(v);}}vector<int>res;while(!q.empty())res.push_back(q.front());sort(res.begin(),res.end());for(int x:res)cout<<x<<" ";cout<<endl;return 0;}
