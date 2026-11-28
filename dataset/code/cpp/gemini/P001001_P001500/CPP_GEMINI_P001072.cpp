#include <iostream>
#include <vector>
#include <algorithm>

void dfs1(int u, const std::vector<std::vector<int>>& adj, std::vector<bool>& vis, std::vector<int>& order) {
    vis[u] = true;
    for (int v : adj[u]) {
        if (!vis[v]) dfs1(v, adj, vis, order);
    }
    order.push_back(u);
}

void dfs2(int u, const std::vector<std::vector<int>>& radj, std::vector<bool>& vis) {
    vis[u] = true;
    for (int v : radj[u]) {
        if (!vis[v]) dfs2(v, radj, vis);
    }
}

int main() {
    int n, m;
    if (std::cin >> n >> m) {
        std::vector<std::vector<int>> adj(n), radj(n);
        for (int i = 0; i < m; i++) {
            int u, v;
            std::cin >> u >> v;
            adj[u].push_back(v);
            radj[v].push_back(u);
        }
        std::vector<bool> vis(n, false);
        std::vector<int> order;
        for (int i = 0; i < n; i++) {
            if (!vis[i]) dfs1(i, adj, vis, order);
        }
        std::fill(vis.begin(), vis.end(), false);
        int scc = 0;
        for (int i = (int)order.size() - 1; i >= 0; i--) {
            int u = order[i];
            if (!vis[u]) {
                dfs2(u, radj, vis);
                scc++;
            }
        }
        std::cout << scc << "\n";
    }
    return 0;
}