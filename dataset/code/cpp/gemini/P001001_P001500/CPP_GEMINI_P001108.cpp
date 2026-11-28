#include <iostream>
#include <vector>
#include <queue>

int main() {
    int n, m, q;
    if (std::cin >> n >> m >> q) {
        std::vector<std::vector<int>> adj(n);
        for (int i = 0; i < m; i++) {
            int u, v;
            std::cin >> u >> v;
            adj[u].push_back(v);
        }
        while (q--) {
            int src, dst;
            std::cin >> src >> dst;
            std::vector<bool> vis(n, false);
            std::queue<int> queue;
            queue.push(src);
            vis[src] = true;
            bool found = false;
            while (!queue.empty()) {
                int u = queue.front();
                queue.pop();
                if (u == dst) { found = true; break; }
                for (int v : adj[u]) {
                    if (!vis[v]) {
                        vis[v] = true;
                        queue.push(v);
                    }
                }
            }
            std::cout << (found ? "YES" : "NO") << "\n";
        }
    }
    return 0;
}