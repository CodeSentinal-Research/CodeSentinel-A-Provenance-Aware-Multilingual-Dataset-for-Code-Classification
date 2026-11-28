#include <iostream>
#include <vector>
#include <algorithm>

int timer_val = 0;

void dfs(int u, int p, const std::vector<std::vector<int>>& adj, std::vector<int>& tin, std::vector<int>& low, std::vector<bool>& isAp) {
    tin[u] = low[u] = timer_val++;
    int children = 0;
    for (int v : adj[u]) {
        if (v == p) continue;
        if (tin[v] != -1) {
            low[u] = std::min(low[u], tin[v]);
        } else {
            dfs(v, u, adj, tin, low, isAp);
            low[u] = std::min(low[u], low[v]);
            if (low[v] >= tin[u] && p != -1) isAp[u] = true;
            children++;
        }
    }
    if (p == -1 && children > 1) isAp[u] = true;
}

int main() {
    int n, m;
    if (std::cin >> n >> m) {
        std::vector<std::vector<int>> adj(n);
        for (int i = 0; i < m; i++) {
            int u, v;
            std::cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        std::vector<int> tin(n, -1), low(n, -1);
        std::vector<bool> isAp(n, false);
        timer_val = 0;
        for (int i = 0; i < n; i++) {
            if (tin[i] == -1) dfs(i, -1, adj, tin, low, isAp);
        }
        bool first = true;
        for (int i = 0; i < n; i++) {
            if (isAp[i]) {
                if (!first) std::cout << " ";
                std::cout << i;
                first = false;
            }
        }
        std::cout << "\n";
    }
    return 0;
}