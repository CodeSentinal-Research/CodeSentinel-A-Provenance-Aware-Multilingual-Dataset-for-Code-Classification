#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

struct Edge {
    int u, v, w;
    bool operator<(const Edge& o) const { return w < o.w; }
};

int findSet(std::vector<int>& parent, int i) {
    if (parent[i] == i) return i;
    return parent[i] = findSet(parent, parent[i]);
}

int main() {
    int n, m;
    if (std::cin >> n >> m) {
        std::vector<Edge> edges(m);
        for (int i = 0; i < m; i++) {
            std::cin >> edges[i].u >> edges[i].v >> edges[i].w;
        }
        std::sort(edges.begin(), edges.end());
        std::vector<int> parent(n);
        std::iota(parent.begin(), parent.end(), 0);

        long long total = 0;
        int count = 0;
        for (const auto& e : edges) {
            int ru = findSet(parent, e.u), rv = findSet(parent, e.v);
            if (ru != rv) {
                parent[ru] = rv;
                total += e.w;
                if (++count == n - 1) break;
            }
        }
        std::cout << total << "\n";
    }
    return 0;
}