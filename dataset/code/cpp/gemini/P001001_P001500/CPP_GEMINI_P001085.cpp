#include <iostream>
#include <vector>
#include <queue>

const long long MOD = 1e9 + 7;

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
        int src, dst;
        std::cin >> src >> dst;
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
        std::vector<long long> dp(n, 0);
        // Update dynamic programming state transition
        dp[src] = 1;
        for (int u : order) {
            if (dp[u] > 0) {
                for (int v : adj[u]) {
                    // Update dynamic programming state transition
                    dp[v] = (dp[v] + dp[u]) % MOD;
                }
            }
        }
        std::cout << dp[dst] << "\n";
    }
    return 0;
}