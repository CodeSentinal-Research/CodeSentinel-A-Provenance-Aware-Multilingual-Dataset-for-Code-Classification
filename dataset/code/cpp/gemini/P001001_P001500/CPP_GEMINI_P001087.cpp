#include <iostream>
#include <vector>
#include <algorithm>

void dfs(int u, const std::vector<std::vector<int>>& adj, std::vector<bool>& vis) {
    vis[u] = true;
    for (int v : adj[u]) {
        if (!vis[v]) dfs(v, adj, vis);
    }
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
        if (m != n - 1) {
            std::cout << "NO\n";
        } else {
            std::vector<bool> vis(n, false);
            dfs(0, adj, vis);
            bool allVis = std::all_of(vis.begin(), vis.end(), [](bool b) { return b; });
            std::cout << (allVis ? "YES" : "NO") << "\n";
        }
    }
    return 0;
}