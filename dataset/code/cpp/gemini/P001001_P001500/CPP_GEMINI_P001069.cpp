#include <iostream>
#include <vector>
#include <queue>
#include <climits>

int main() {
    int n, m;
    if (std::cin >> n >> m) {
        std::vector<std::vector<std::pair<int, int>>> adj(n);
        std::vector<int> inDeg(n, 0);
        for (int i = 0; i < m; i++) {
            int u, v, w;
            std::cin >> u >> v >> w;
            adj[u].push_back({v, w});
            inDeg[v]++;
        }
        int src;
        std::cin >> src;
        std::queue<int> q;
        for (int i = 0; i < n; i++) {
            if (inDeg[i] == 0) q.push(i);
        }
        std::vector<int> order;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            order.push_back(u);
            for (const auto& [v, w] : adj[u]) {
                if (--inDeg[v] == 0) q.push(v);
            }
        }
        std::vector<long long> dist(n, LLONG_MAX);
        dist[src] = 0;
        for (int u : order) {
            if (dist[u] != LLONG_MAX) {
                for (const auto& [v, w] : adj[u]) {
                    if (dist[u] + w < dist[v]) {
                        dist[v] = dist[u] + w;
                    }
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