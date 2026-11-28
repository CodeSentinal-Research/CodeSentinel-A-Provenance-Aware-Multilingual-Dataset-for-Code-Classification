#include <iostream>
#include <vector>
#include <queue>

int main() {
    int n, m, k;
    if (std::cin >> n >> m >> k) {
        std::vector<std::vector<int>> adj(n);
        for (int i = 0; i < m; i++) {
            int u, v;
            std::cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        std::vector<int> dist(n, -1);
        std::queue<int> q;
        for (int i = 0; i < k; i++) {
            int s;
            std::cin >> s;
            dist[s] = 0;
            q.push(s);
        }
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v : adj[u]) {
                if (dist[v] == -1) {
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
        }
        for (int i = 0; i < n; i++) {
            std::cout << dist[i] << (i == n - 1 ? "" : " ");
        }
        std::cout << "\n";
    }
    return 0;
}