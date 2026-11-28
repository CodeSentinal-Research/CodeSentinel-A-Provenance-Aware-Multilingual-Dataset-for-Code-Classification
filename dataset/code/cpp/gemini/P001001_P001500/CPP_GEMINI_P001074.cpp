#include <iostream>
#include <vector>
#include <queue>
#include <climits>

int main() {
    int n, m;
    if (std::cin >> n >> m) {
        std::vector<std::vector<std::pair<int, int>>> adj(n);
        for (int i = 0; i < m; i++) {
            int u, v, w;
            std::cin >> u >> v >> w;
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        int src;
        std::cin >> src;
        std::vector<long long> dist(n, LLONG_MAX);
        dist[src] = 0;
        std::priority_queue<std::pair<long long, int>, std::vector<std::pair<long long, int>>, std::greater<std::pair<long long, int>>> pq;
        pq.push({0, src});

        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();
            if (d > dist[u]) continue;
            for (const auto& [v, w] : adj[u]) {
                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }
        for (int i = 0; i < n; i++) {
            std::cout << (dist[i] == LLONG_MAX ? -1 : dist[i]) << (i == n - 1 ? "" : " ");
        }
        std::cout << "\n";
    }
    return 0;
}