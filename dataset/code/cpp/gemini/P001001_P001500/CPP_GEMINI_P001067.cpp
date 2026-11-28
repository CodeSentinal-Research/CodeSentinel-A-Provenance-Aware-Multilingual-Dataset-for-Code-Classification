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
        }
        int src;
        std::cin >> src;
        std::vector<bool> vis(n, false);
        std::queue<int> q;
        q.push(src);
        vis[src] = true;
        int count = 0;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            count++;
            for (int v : adj[u]) {
                if (!vis[v]) {
                    vis[v] = true;
                    q.push(v);
                }
            }
        }
        std::cout << count << "\n";
    }
    return 0;
}