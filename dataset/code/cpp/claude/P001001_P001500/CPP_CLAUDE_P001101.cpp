#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Solution{
public:
    void bfs(vector<vector<int>>& adj, int src, int n){
        vector<bool> vis(n+1,false);
        queue<int> q;
        vis[src]=true; q.push(src);
        while(!q.empty()){
            int u=q.front();q.pop();cout<<u<<" ";
            for(int v:adj[u]) if(!vis[v]){vis[v]=true;q.push(v);}
        }
        cout<<"\n";
    }
};
int main(){
    int n,m,src;cin>>n>>m;
    vector<vector<int>> adj(n+1);
    for(int i=0;i<m;i++){int u,v;cin>>u>>v;adj[u].push_back(v);adj[v].push_back(u);}
    cin>>src;
    Solution().bfs(adj,src,n);
}
