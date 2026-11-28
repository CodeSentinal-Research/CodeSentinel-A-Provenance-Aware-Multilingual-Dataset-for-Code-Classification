#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main(){int n,k;cin>>n>>k;vector<int>a(n),b(n);for(int i=0;i<n;i++)cin>>a[i];for(int i=0;i<n;i++)cin>>b[i];priority_queue<pair<int,pair<int,int>>>pq;pq.push({a[0]+b[0],{0,0}});vector<vector<bool>>vis(n,vector<bool>(n,false));vis[0][0]=true;while(k-->0){auto[v,p]=pq.top();pq.pop();cout<<v<<" ";int i=p.first,j=p.second;if(i+1<n&&!vis[i+1][j]){pq.push({a[i+1]+b[j],{i+1,j}});vis[i+1][j]=true;}if(j+1<n&&!vis[i][j+1]){pq.push({a[i]+b[j+1],{i,j+1}});vis[i][j+1]=true;}}cout<<endl;return 0;}
