#include<bits/stdc++.h>
using namespace std;
int n;vector<vector<int>>c;void dfs(int u,vector<bool>&vis){vis[u]=true;for(int v=0;v<n;v++)if(c[u][v]&&!vis[v])dfs(v,vis);}
int main(){cin>>n;c.resize(n,vector<int>(n));for(int i=0;i<n;i++)for(int j=0;j<n;j++)cin>>c[i][j];vector<bool>vis(n,false);int cnt=0;for(int i=0;i<n;i++)if(!vis[i]){dfs(i,vis);cnt++;}cout<<cnt<<endl;return 0;}
