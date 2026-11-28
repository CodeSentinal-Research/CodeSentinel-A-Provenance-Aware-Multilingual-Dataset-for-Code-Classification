#include <iostream>
#include <vector>
bool is_safe(int node, int c, const std::vector<std::vector<int>>& adj, const std::vector<int>& colors) {
    for (int neighbor : adj[node]) {
        if (colors[neighbor] == c) return false;
    }
    return true;
}
bool backtrack(int node, int v, int m, const std::vector<std::vector<int>>& adj, std::vector<int>& colors) {
    if (node == v) return true;
    for (int c = 1; c <= m; c++) {
        if (is_safe(node, c, adj, colors)) {
            colors[node] = c;
            if (backtrack(node + 1, v, m, adj, colors)) return true;
            colors[node] = 0;
        }
    }
    return false;
}
int main() {
    int v, e;
    if (std::cin >> v >> e) {
        std::vector<std::vector<int>> adj(v);
        for (int i = 0; i < e; i++) {
            int u, w; std::cin >> u >> w;
            adj[u].push_back(w); adj[w].push_back(u);
        }
        int m; std::cin >> m;
        std::vector<int> colors(v, 0);
        std::cout << (backtrack(0, v, m, adj, colors) ? "true" : "false") << std::endl;
    }
    return 0;
}