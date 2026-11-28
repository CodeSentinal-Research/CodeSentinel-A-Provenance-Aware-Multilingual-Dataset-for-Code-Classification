#include <iostream>
#include <vector>

bool dfs(int u, int count, int n, const std::vector<std::vector<int>>& adj, std::vector<bool>& vis) {
    if (count == n) return true;
    vis[u] = true;
    for (int v : adj[u]) {
        if (!vis[v] && dfs(v, count + 1, n, adj, vis)) return true;
    }
    vis[u] = false;
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
            adj[v].push_back(u);
        }
        std::vector<bool> vis(n, false);
        bool found = false;
        for (int i = 0; i < n; i++) {
            if (dfs(i, 1, n, adj, vis)) {
                found = true;
                break;
            }
        }
        std::cout << (found ? "YES" : "NO") << "\n";
    }
    return 0;
}