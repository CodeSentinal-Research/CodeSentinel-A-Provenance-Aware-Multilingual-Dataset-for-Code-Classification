#include<bits/stdc++.h>
using namespace std;
int r,c;vector<string>g;void dfs(int i,int j){if(i<0||i>=r||j<0||j>=c||g[i][j]!='O')return;g[i][j]='*';dfs(i+1,j);dfs(i-1,j);dfs(i,j+1);dfs(i,j-1);}
int main(){cin>>r>>c;g.resize(r);for(int i=0;i<r;i++)cin>>g[i];for(int i=0;i<r;i++){if(g[i][0]=='O')dfs(i,0);if(g[i][c-1]=='O')dfs(i,c-1);}for(int j=0;j<c;j++){if(g[0][j]=='O')dfs(0,j);if(g[r-1][j]=='O')dfs(r-1,j);}for(int i=0;i<r;i++){for(int j=0;j<c;j++){if(g[i][j]=='*')g[i][j]='O';else if(g[i][j]=='O')g[i][j]='X';cout<<g[i][j];}cout<<endl;}return 0;}
