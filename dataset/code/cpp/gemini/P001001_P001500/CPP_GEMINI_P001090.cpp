#include <iostream>
#include <vector>
#include <queue>

std::pair<int, int> bfs(int src, int n, const std::vector<std::vector<int>>& adj) {
    std::vector<int> dist(n, -1);
    dist[src] = 0;
    std::queue<int> q;
    q.push(src);
    int farthest = src;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
                if (dist[v] > dist[farthest]) farthest = v;
            }
        }
    }
    return {farthest, dist[farthest]};
}

int main() {
    int n;
    if (std::cin >> n) {
        if (n <= 1) {
            std::cout << 0 << "\n";
            return 0;
        }
        std::vector<std::vector<int>> adj(n);
        for (int i = 0; i < n - 1; i++) {
            int u, v;
            std::cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        auto [u, _] = bfs(0, n, adj);
        auto [__, diam] = bfs(u, n, adj);
        std::cout << diam << "\n";
    }
    return 0;
}