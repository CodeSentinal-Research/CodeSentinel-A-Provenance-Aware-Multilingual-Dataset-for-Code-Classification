#include <iostream>
#include <vector>
#include <queue>

int main() {
    int n, m;
    if (std::cin >> n >> m) {
        std::vector<std::vector<int>> adj(n);
        std::vector<int> inDeg(n, 0);
        for (int i = 0; i < m; i++) {
            int u, v;
            std::cin >> u >> v;
            adj[u].push_back(v);
            inDeg[v]++;
        }
        std::queue<int> q;
        for (int i = 0; i < n; i++) {
            if (inDeg[i] == 0) q.push(i);
        }
        std::vector<int> order;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            order.push_back(u);
            for (int v : adj[u]) {
                if (--inDeg[v] == 0) q.push(v);
            }
        }
        for (size_t i = 0; i < order.size(); i++) {
            std::cout << order[i] << (i == order.size() - 1 ? "" : " ");
        }
        std::cout << "\n";
    }
    return 0;
}