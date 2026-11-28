#include <iostream>
#include <vector>
#include <algorithm>

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
        int target;
        std::cin >> target;
        std::sort(adj[target].begin(), adj[target].end());
        for (size_t i = 0; i < adj[target].size(); i++) {
            std::cout << adj[target][i] << (i == adj[target].size() - 1 ? "" : " ");
        }
        std::cout << "\n";
    }
    return 0;
}