#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

int main() {
    int n;
    if (std::cin >> n) {
        if (n == 1) {
            std::cout << 0 << "\n";
            return 0;
        }
        std::vector<std::vector<int>> adj(n);
        std::vector<int> deg(n, 0);
        for (int i = 0; i < n - 1; i++) {
            int u, v;
            std::cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
            deg[u]++;
            deg[v]++;
        }
        std::queue<int> leaves;
        for (int i = 0; i < n; i++) {
            if (deg[i] == 1) leaves.push(i);
        }
        int remaining = n;
        while (remaining > 2) {
            int count = leaves.size();
            remaining -= count;
            for (int i = 0; i < count; i++) {
                int leaf = leaves.front();
                leaves.pop();
                for (int neighbor : adj[leaf]) {
                    if (--deg[neighbor] == 1) {
                        leaves.push(neighbor);
                    }
                }
            }
        }
        std::vector<int> res;
        while (!leaves.empty()) {
            res.push_back(leaves.front());
            leaves.pop();
        }
        std::sort(res.begin(), res.end());
        for (size_t i = 0; i < res.size(); i++) {
            std::cout << res[i] << (i == res.size() - 1 ? "" : " ");
        }
        std::cout << "\n";
    }
    return 0;
}