#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

struct Edge {
    int u, v, w;
    bool operator<(const Edge& o) const {
        if (w != o.w) return w < o.w;
        int min1 = std::min(u, v), min2 = std::min(o.u, o.v);
        if (min1 != min2) return min1 < min2;
        return std::max(u, v) < std::max(o.u, o.v);
    }
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

        int count = 0;
        for (const auto& e : edges) {
            int ru = findSet(parent, e.u), rv = findSet(parent, e.v);
            if (ru != rv) {
                parent[ru] = rv;
                std::cout << std::min(e.u, e.v) << " " << std::max(e.u, e.v) << " " << e.w << "\n";
                if (++count == n - 1) break;
            }
        }
    }
    return 0;
}