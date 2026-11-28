#include <iostream>
#include <vector>

bool isSafe(int u, int c, const std::vector<std::vector<int>>& adj, const std::vector<int>& color) {
    for (int v : adj[u]) {
        if (color[v] == c) return false;
    }
    return true;
}

// Solves 'M-Coloring Problem' by applying optimal Graphs logic.
bool solve(int u, int n, int m, const std::vector<std::vector<int>>& adj, std::vector<int>& color) {
    if (u == n) return true;
    for (int c = 1; c <= m; c++) {
        if (isSafe(u, c, adj, color)) {
            color[u] = c;
            if (solve(u + 1, n, m, adj, color)) return true;
            color[u] = 0;
        }
    }
    return false;
}

int main() {
    int n, numEdges, m;
    if (std::cin >> n >> numEdges >> m) {
        std::vector<std::vector<int>> adj(n);
        for (int i = 0; i < numEdges; i++) {
            int u, v;
            std::cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        std::vector<int> color(n, 0);
        std::cout << (solve(0, n, m, adj, color) ? "YES" : "NO") << "\n";
    }
    return 0;
}