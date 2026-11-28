#include <iostream>
#include <vector>
#include <stack>
using namespace std;
void dfs(int u,vector<vector<int>>&adj,vector<bool>&vis,stack<int>&st){vis[u]=true;for(int v:adj[u])if(!vis[v])dfs(v,adj,vis,st);st.push(u);}
int main(){int n,m;cin>>n>>m;vector<vector<int>>adj(n+1),radj(n+1);for(int i=0;i<m;i++){int u,v;cin>>u>>v;adj[u].push_back(v);radj[v].push_back(u);}vector<bool>vis(n+1,false);stack<int>st;for(int i=1;i<=n;i++)if(!vis[i])dfs(i,adj,vis,st);fill(vis.begin(),vis.end(),false);int c=0;while(!st.empty()){int u=st.top();st.pop();if(!vis[u]){dfs(u,radj,vis,stack<int>());c++;}}cout<<c<<endl;return 0;}
