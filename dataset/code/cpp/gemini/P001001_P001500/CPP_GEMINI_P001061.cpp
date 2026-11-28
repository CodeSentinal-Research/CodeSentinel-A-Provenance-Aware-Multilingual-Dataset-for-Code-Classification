#include <iostream>
#include <vector>

bool dfs(int u, const std::vector<std::vector<int>>& adj, std::vector<int>& vis) {
    vis[u] = 1;
    for (int v : adj[u]) {
        if (vis[v] == 1) return true;
        if (vis[v] == 0 && dfs(v, adj, vis)) return true;
    }
    vis[u] = 2;
    return false;
}

int main() {
    int n, m;
    if (std::cin >> n >> m) {
        std::vector<std::vector<int>> adj(n);
        for (int i = 0; i < m; i++) {
            int u, v;
            std::cin >> u >> v;
            adj[u].push_back(v);
        }
        std::vector<int> vis(n, 0);
        bool cycle = false;
        for (int i = 0; i < n; i++) {
            if (vis[i] == 0 && dfs(i, adj, vis)) {
                cycle = true;
                break;
            }
        }
        std::cout << (cycle ? "YES" : "NO") << "\n";
    }
    return 0;
}