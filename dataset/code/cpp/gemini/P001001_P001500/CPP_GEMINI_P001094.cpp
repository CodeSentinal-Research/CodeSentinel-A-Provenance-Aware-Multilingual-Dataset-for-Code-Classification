#include <iostream>
#include <vector>

bool bpm(int u, int n, const std::vector<std::vector<bool>>& adj, std::vector<bool>& seen, std::vector<int>& matchR) {
    for (int v = 0; v < n; v++) {
        if (adj[u][v] && !seen[v]) {
            seen[v] = true;
            if (matchR[v] < 0 || bpm(matchR[v], n, adj, seen, matchR)) {
                matchR[v] = u;
                return true;
            }
        }
    }
    return false;
}

int main() {
    int m, n, k;
    if (std::cin >> m >> n >> k) {
        std::vector<std::vector<bool>> adj(m, std::vector<bool>(n, false));
        for (int i = 0; i < k; i++) {
            int u, v;
            std::cin >> u >> v;
            adj[u][v] = true;
        }
        std::vector<int> matchR(n, -1);
        int count = 0;
        for (int u = 0; u < m; u++) {
            std::vector<bool> seen(n, false);
            if (bpm(u, n, adj, seen, matchR)) count++;
        }
        std::cout << count << "\n";
    }
    return 0;
}