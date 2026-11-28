#include <iostream>
#include <vector>
#include <queue>

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
        std::vector<bool> vis(n, false);
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;
        pq.push({0, 0});
        long long total = 0;

        while (!pq.empty()) {
            auto [w, u] = pq.top();
            pq.pop();
            if (vis[u]) continue;
            vis[u] = true;
            total += w;
            for (const auto& [v, weight] : adj[u]) {
                if (!vis[v]) {
                    pq.push({weight, v});
                }
            }
        }
        std::cout << total << "\n";
    }
    return 0;
}