#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

struct Conn {
    int u, v, cost;
    bool operator<(const Conn& o) const { return cost < o.cost; }
};

int findSet(std::vector<int>& parent, int i) {
    if (parent[i] == i) return i;
    return parent[i] = findSet(parent, parent[i]);
}

int main() {
    int n, m;
    if (std::cin >> n >> m) {
        std::vector<Conn> conns(m);
        for (int i = 0; i < m; i++) {
            std::cin >> conns[i].u >> conns[i].v >> conns[i].cost;
        }
        std::sort(conns.begin(), conns.end());
        std::vector<int> parent(n + 1);
        std::iota(parent.begin(), parent.end(), 0);

        long long total = 0;
        int count = 0;
        for (const auto& c : conns) {
            int ru = findSet(parent, c.u), rv = findSet(parent, c.v);
            if (ru != rv) {
                parent[ru] = rv;
                total += c.cost;
                if (++count == n - 1) break;
            }
        }
        std::cout << (count == n - 1 ? total : -1) << "\n";
    }
    return 0;
}