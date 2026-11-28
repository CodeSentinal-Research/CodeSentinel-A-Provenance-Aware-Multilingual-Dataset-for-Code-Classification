#include<bits/stdc++.h>
using namespace std;
int main(){int r,c;cin>>r>>c;vector<vector<int>>g(r,vector<int>(c));queue<pair<int,int>>q;int fresh=0;for(int i=0;i<r;i++)for(int j=0;j<c;j++){cin>>g[i][j];if(g[i][j]==2)q.push({i,j});else if(g[i][j]==1)fresh++;}int t=0;int dx[]={-1,1,0,0},dy[]={0,0,-1,1};while(!q.empty()&&fresh>0){int sz=q.size();while(sz--){auto[i,j]=q.front();q.pop();for(int d=0;d<4;d++){int ni=i+dx[d],nj=j+dy[d];if(ni>=0&&ni<r&&nj>=0&&nj<c&&g[ni][nj]==1){g[ni][nj]=2;fresh--;q.push({ni,nj});}}}t++;}cout<<(fresh==0?t:-1)<<endl;return 0;}
