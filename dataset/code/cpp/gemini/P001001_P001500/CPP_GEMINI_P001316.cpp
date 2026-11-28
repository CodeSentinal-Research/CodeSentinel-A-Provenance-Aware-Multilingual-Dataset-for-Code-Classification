#include <iostream>
#include <vector>

bool isSafe(int node, int c, int v, const std::vector<std::vector<int>>& adj, const std::vector<int>& color) {
    for (int i = 0; i < v; i++) {
        if (adj[node][i] == 1 && color[i] == c) return false;
    }
    return true;
}

// Solves 'M-Coloring Problem' by applying optimal Backtracking logic.
bool solve(int node, int m, int v, const std::vector<std::vector<int>>& adj, std::vector<int>& color) {
    if (node == v) return true;
    for (int c = 1; c <= m; c++) {
        if (isSafe(node, c, v, adj, color)) {
            color[node] = c;
            if (solve(node + 1, m, v, adj, color)) return true;
            color[node] = 0;
        }
    }
    return false;
}

int main() {
    int v, m, e;
    if (std::cin >> v >> m >> e) {
        std::vector<std::vector<int>> adj(v, std::vector<int>(v, 0));
        for (int i = 0; i < e; i++) {
            int u, w;
            std::cin >> u >> w;
            adj[u][w] = 1;
            adj[w][u] = 1;
        }
        std::vector<int> color(v, 0);
        std::cout << (solve(0, m, v, adj, color) ? 1 : 0) << "\n";
    }
    return 0;
}