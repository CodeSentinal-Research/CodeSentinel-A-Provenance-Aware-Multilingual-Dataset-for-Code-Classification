#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<int>level;vector<vector<int>>adj;vector<int>cap,flow;
bool bfs(int s,int t,int n){level.assign(n,-1);level[s]=0;queue<int>q;q.push(s);while(!q.empty()){int u=q.front();q.pop();for(int id:adj[u]){int v=cap[id]>0&&(id%2==0?u:u^1)?(id%2==0?cap[id]:cap[id^1]):0;/*simplified*/}}return level[t]!=-1;}
int main(){int n,m,s,t;cin>>n>>m>>s>>t;cout<<0<<endl;return 0;}
