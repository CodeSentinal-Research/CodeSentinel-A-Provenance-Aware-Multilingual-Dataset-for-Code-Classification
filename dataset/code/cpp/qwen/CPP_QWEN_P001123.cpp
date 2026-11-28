#include<bits/stdc++.h>
using namespace std;
int main(){int n,m,t;cin>>n>>m>>t;vector<vector<int>>d(n,vector<int>(n,1e9));for(int i=0;i<n;i++)d[i][i]=0;for(int i=0;i<m;i++){int u,v,w;cin>>u>>v>>w;d[u][v]=min(d[u][v],w);d[v][u]=min(d[v][u],w);}for(int k=0;k<n;k++)for(int i=0;i<n;i++)for(int j=0;j<n;j++)d[i][j]=min(d[i][j],d[i][k]+d[k][j]);int ans=n,mx=1e9;for(int i=0;i<n;i++){int cnt=0;for(int j=0;j<n;j++)if(d[i][j]<=t)cnt++;if(cnt<=mx){mx=cnt;ans=i;}}cout<<ans<<endl;return 0;}
