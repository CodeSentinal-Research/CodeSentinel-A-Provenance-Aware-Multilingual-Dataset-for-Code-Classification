#include <iostream>
#include <vector>
#include <climits>

struct Edge {
    int u, v, w;
};

int main() {
    int n, m;
    if (std::cin >> n >> m) {
        std::vector<Edge> edges(m);
        for (int i = 0; i < m; i++) {
            std::cin >> edges[i].u >> edges[i].v >> edges[i].w;
        }
        int src;
        std::cin >> src;
        std::vector<long long> dist(n, LLONG_MAX);
        dist[src] = 0;

        for (int iter = 0; iter < n - 1; iter++) {
            for (const auto& e : edges) {
                if (dist[e.u] != LLONG_MAX && dist[e.u] + e.w < dist[e.v]) {
                    dist[e.v] = dist[e.u] + e.w;
                }
            }
        }

        bool negCycle = false;
        for (const auto& e : edges) {
            if (dist[e.u] != LLONG_MAX && dist[e.u] + e.w < dist[e.v]) {
                negCycle = true;
                break;
            }
        }

        if (negCycle) {
            std::cout << "NEGATIVE CYCLE\n";
        } else {
            for (int i = 0; i < n; i++) {
                std::cout << (dist[i] == LLONG_MAX ? -1 : dist[i]) << (i == n - 1 ? "" : " ");
            }
            std::cout << "\n";
        }
    }
    return 0;
}