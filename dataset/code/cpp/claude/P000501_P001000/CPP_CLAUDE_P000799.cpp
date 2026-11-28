#include<iostream>
#include<vector>
using namespace std;
int main(){int n,m;cin>>n>>m;
vector<vector<long long>>g(n,vector<long long>(m)),p(n+1,vector<long long>(m+1,0));
for(auto&row:g)for(auto&v:row)cin>>v;
for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)p[i][j]=g[i-1][j-1]+p[i-1][j]+p[i][j-1]-p[i-1][j-1];
for(int i=1;i<=n;i++){for(int j=1;j<=m;j++)cout<<p[i][j]<<" \n"[j==m];}}
