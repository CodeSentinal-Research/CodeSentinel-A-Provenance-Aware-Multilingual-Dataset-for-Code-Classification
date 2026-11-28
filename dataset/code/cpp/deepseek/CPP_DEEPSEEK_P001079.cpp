#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

class Solution {
public:
    void findBridges(int n, vector<int> adj[], vector<pair<int, int>>& bridges) {
        int u, v, sz, cnt;
        vector<bool> visited(n + 1, false);
        vector<int> disc(n + 1, -1), low(n + 1, -1), parent(n + 1, -1);
        queue<int> q;

        for(u = 1; u <= n; u++) {
            if(!visited[u]) {
                dfs(u, adj, visited, disc, low, parent, bridges, q);
            }
        }

        while(!q.empty()) {
            v = q.front();
            q.pop();
            adj[v].clear();
        }

        sort(bridges.begin(), bridges.end());

        for(auto bridge : bridges) {
            cout << bridge.first << " " << bridge.second << endl;
        }
    }

    void dfs(int u, vector<int> adj[], vector<bool>& visited, vector<int>& disc, vector<int>& low, vector<int>& parent, vector<pair<int, int>>& bridges, queue<int>& q) {
        visited[u] = true;
        disc[u] = low[u] = ++cnt;
        q.push(u);

        for(auto v : adj[u]) {
            if(!visited[v]) {
                parent[v] = u;
                dfs(v, adj, visited, disc, low, parent, bridges, q);
                low[u] = min(low[u], low[v]);
                if(low[v] > disc[u]) {
                    bridges.push_back(make_pair(u, v));
                }
            } else if(v != parent[u]) {
                low[u] = min(low[u], disc[v]);
            }
        }
    }
};