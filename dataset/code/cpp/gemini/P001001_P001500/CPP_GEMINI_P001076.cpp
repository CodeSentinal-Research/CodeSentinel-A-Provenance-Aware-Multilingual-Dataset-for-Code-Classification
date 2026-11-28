#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

int main() {
    int n, m;
    if (std::cin >> n >> m) {
        std::vector<std::vector<long long>> dist(n, std::vector<long long>(n, LLONG_MAX));
        for (int i = 0; i < n; i++) dist[i][i] = 0;
        for (int i = 0; i < m; i++) {
            int u, v, w;
            std::cin >> u >> v >> w;
            dist[u][v] = std::min(dist[u][v], (long long)w);
        }

        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (dist[i][k] != LLONG_MAX && dist[k][j] != LLONG_MAX) {
                        dist[i][j] = std::min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                std::cout << (dist[i][j] == LLONG_MAX ? -1 : dist[i][j]) << (j == n - 1 ? "" : " ");
            }
            std::cout << "\n";
        }
    }
    return 0;
}