#include <iostream>
#include <vector>
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
            int type, u, v;
            std::cin >> type >> u >> v;
            if (type == 1) {
                int ru = findSet(parent, u), rv = findSet(parent, v);
                if (ru != rv) parent[ru] = rv;
            } else {
                std::cout << (findSet(parent, u) == findSet(parent, v) ? "YES" : "NO") << "\n";
            }
        }
    }
    return 0;
}