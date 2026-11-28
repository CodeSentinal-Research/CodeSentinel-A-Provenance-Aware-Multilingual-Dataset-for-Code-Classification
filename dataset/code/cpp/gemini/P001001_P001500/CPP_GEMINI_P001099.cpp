#include <iostream>
#include <vector>
#include <numeric>

int findSet(std::vector<int>& parent, int i) {
    if (parent[i] == i) return i;
    return parent[i] = findSet(parent, parent[i]);
}

int main() {
    int n, m;
    if (std::cin >> n >> m) {
        std::vector<int> parent(n);
        std::iota(parent.begin(), parent.end(), 0);
        bool cycle = false;
        for (int i = 0; i < m; i++) {
            int u, v;
            std::cin >> u >> v;
            int ru = findSet(parent, u), rv = findSet(parent, v);
            if (ru == rv) {
                cycle = true;
            } else {
                parent[ru] = rv;
            }
        }
        std::cout << (cycle ? "YES" : "NO") << "\n";
    }
    return 0;
}