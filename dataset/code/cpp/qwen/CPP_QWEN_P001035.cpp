#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main(){int n,k;cin>>n>>k;vector<vector<int>>a(n,vector<int>(n));for(int i=0;i<n;i++)for(int j=0;j<n;j++)cin>>a[i][j];priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<>>pq;pq.push({a[0][0],{0,0}});vector<vector<bool>>vis(n,vector<bool>(n,false));vis[0][0]=true;int res=0;while(k-->0){auto[v,p]=pq.top();pq.pop();res=v;int r=p.first,c=p.second;if(r+1<n&&!vis[r+1][c]){pq.push({a[r+1][c],{r+1,c}});vis[r+1][c]=true;}if(c+1<n&&!vis[r][c+1]){pq.push({a[r][c+1],{r,c+1}});vis[r][c+1]=true;}}cout<<res<<endl;return 0;}
