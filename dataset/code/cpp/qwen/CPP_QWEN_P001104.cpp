#include<bits/stdc++.h>
using namespace std;
int main(){int n;cin>>n;vector<vector<int>>adj(n);for(int i=0;i<n;i++){int sz;cin>>sz;adj[i].resize(sz);for(int j=0;j<sz;j++)cin>>adj[i][j];}for(int i=0;i<n;i++){cout<<i<<":";for(int x:adj[i])cout<<" "<<x;cout<<endl;}return 0;}
