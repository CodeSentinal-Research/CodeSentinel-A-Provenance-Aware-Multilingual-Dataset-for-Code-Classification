#include<bits/stdc++.h>
using namespace std;
int main(){int n,m;cin>>n>>m;vector<vector<int>>d(n,vector<int>(n,0));for(int i=0;i<m;i++){int u,v;cin>>u>>v;d[u][v]=1;}for(int i=0;i<n;i++)d[i][i]=1;for(int k=0;k<n;k++)for(int i=0;i<n;i++)for(int j=0;j<n;j++)if(d[i][k]&&d[k][j])d[i][j]=1;for(int i=0;i<n;i++){for(int j=0;j<n;j++)cout<<d[i][j]<<" ";cout<<endl;}return 0;}
