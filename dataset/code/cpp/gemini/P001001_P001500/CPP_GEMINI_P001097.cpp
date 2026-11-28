#include <iostream>
#include <vector>
#include <string>
#include <numeric>

int findSet(std::vector<int>& parent, int i) {
    if (parent[i] == i) return i;
    return parent[i] = findSet(parent, parent[i]);
}

int main() {
    int n, q;
    if (std::cin >> n >> q) {
        std::vector<int> parent(n);
        std::iota(parent.begin(), parent.end(), 0);

        while (q--) {
            std::string op;
            std::cin >> op;
            if (op == "UNION") {
                int u, v;
                std::cin >> u >> v;
                int ru = findSet(parent, u), rv = findSet(parent, v);
                if (ru != rv) parent[ru] = rv;
            } else if (op == "FIND") {
                int u;
                std::cin >> u;
                std::cout << findSet(parent, u) << "\n";
            } else if (op == "CONNECTED") {
                int u, v;
                std::cin >> u >> v;
                std::cout << (findSet(parent, u) == findSet(parent, v) ? "YES" : "NO") << "\n";
            }
        }
    }
    return 0;
}