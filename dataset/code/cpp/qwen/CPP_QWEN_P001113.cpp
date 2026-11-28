#include<bits/stdc++.h>
using namespace std;
int r,c;vector<string>g;void dfs(int i,int j){if(i<0||i>=r||j<0||j>=c||g[i][j]!='1')return;g[i][j]='0';dfs(i+1,j);dfs(i-1,j);dfs(i,j+1);dfs(i,j-1);}
int main(){cin>>r>>c;g.resize(r);for(int i=0;i<r;i++)cin>>g[i];int cnt=0;for(int i=0;i<r;i++)for(int j=0;j<c;j++)if(g[i][j]=='1'){dfs(i,j);cnt++;}cout<<cnt<<endl;return 0;}
