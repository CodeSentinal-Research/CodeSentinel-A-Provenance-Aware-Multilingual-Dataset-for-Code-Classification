#include<bits/stdc++.h>
using namespace std;
int main(){int n;cin>>n;vector<vector<int>>g(n,vector<int>(n));for(int i=0;i<n;i++)for(int j=0;j<n;j++)cin>>g[i][j];if(g[0][0]==1||g[n-1][n-1]==1){cout<<-1<<endl;return 0;}queue<tuple<int,int,int>>q;q.push({0,0,1});g[0][0]=1;int dx[]={-1,1,0,0,1,1,-1,-1},dy[]={0,0,-1,1,1,-1,1,-1};while(!q.empty()){auto[r,c,d]=q.front();q.pop();if(r==n-1&&c==n-1){cout<<d<<endl;return 0;}for(int i=0;i<8;i++){int nr=r+dx[i],nc=c+dy[i];if(nr>=0&&nr<n&&nc>=0&&nc<n&&g[nr][nc]==0){g[nr][nc]=1;q.push({nr,nc,d+1});}}}cout<<-1<<endl;return 0;}
