#include <iostream>
#include <vector>

int main() {
    int n, q;
    if (std::cin >> n >> q) {
        std::vector<int> parent(n, 0);
        for (int i = 1; i < n; i++) std::cin >> parent[i];
        std::vector<int> depth(n, 0);
        for (int i = 1; i < n; i++) {
            int d = 0, curr = i;
            while (curr != 0) {
                curr = parent[curr];
                d++;
            }
            depth[i] = d;
        }
        while (q--) {
            int u, v;
            std::cin >> u >> v;
            while (depth[u] > depth[v]) u = parent[u];
            while (depth[v] > depth[u]) v = parent[v];
            while (u != v) {
                u = parent[u];
                v = parent[v];
            }
            std::cout << u << "\n";
        }
    }
    return 0;
}