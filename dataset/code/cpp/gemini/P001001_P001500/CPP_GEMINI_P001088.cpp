#include <iostream>
#include <vector>
#include <queue>

int main() {
    int n, m;
    if (std::cin >> n >> m) {
        std::vector<std::vector<int>> adj(n);
        for (int i = 0; i < m; i++) {
            int u, v;
            std::cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int src, k;
        std::cin >> src >> k;
        std::vector<int> dist(n, -1);
        dist[src] = 0;
        std::queue<int> q;
        q.push(src);

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
        int count = 0;
        for (int d : dist) if (d == k) count++;
        std::cout << count << "\n";
    }
    return 0;
}