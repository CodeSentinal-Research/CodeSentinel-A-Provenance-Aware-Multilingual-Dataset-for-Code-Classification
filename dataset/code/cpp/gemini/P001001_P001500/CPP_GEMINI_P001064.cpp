#include <iostream>
#include <set>
#include <algorithm>

int main() {
    int n, m;
    if (std::cin >> n >> m) {
        std::set<std::pair<int, int>> edges;
        for (int i = 0; i < m; i++) {
            int u, v;
            std::cin >> u >> v;
            edges.insert({std::min(u, v), std::max(u, v)});
        }
        int qu, qv;
        std::cin >> qu >> qv;
        bool exists = edges.count({std::min(qu, qv), std::max(qu, qv)}) > 0;
        std::cout << (exists ? "YES" : "NO") << "\n";
    }
    return 0;
}