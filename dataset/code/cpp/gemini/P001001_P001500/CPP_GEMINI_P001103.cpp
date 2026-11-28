#include <vector>
#include <algorithm>

class Solution {
    int timer = 0;
    void dfs(int u, int p, const std::vector<std::vector<int>>& adj, std::vector<int>& tin, std::vector<int>& low, std::vector<std::vector<int>>& bridges) {
        tin[u] = low[u] = timer++;
        for (int v : adj[u]) {
            if (v == p) continue;
            if (tin[v] != -1) {
                low[u] = std::min(low[u], tin[v]);
            } else {
                dfs(v, u, adj, tin, low, bridges);
                low[u] = std::min(low[u], low[v]);
                if (low[v] > tin[u]) {
                    bridges.push_back({u, v});
                }
            }
        }
    }
public:
    std::vector<std::vector<int>> criticalConnections(int n, std::vector<std::vector<int>>& connections) {
        std::vector<std::vector<int>> adj(n);
        for (const auto& e : connections) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        std::vector<int> tin(n, -1), low(n, -1);
        std::vector<std::vector<int>> bridges;
        timer = 0;
        dfs(0, -1, adj, tin, low, bridges);
        return bridges;
    }
};