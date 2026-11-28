#include <iostream>
#include <vector>

int main() {
    int n, m;
    if (std::cin >> n >> m) {
        std::vector<std::vector<int>> reach(n, std::vector<int>(n, 0));
        for (int i = 0; i < n; i++) reach[i][i] = 1;
        for (int i = 0; i < m; i++) {
            int u, v;
            std::cin >> u >> v;
            reach[u][v] = 1;
        }

        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (reach[i][k] && reach[k][j]) {
                        reach[i][j] = 1;
                    }
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                std::cout << reach[i][j] << (j == n - 1 ? "" : " ");
            }
            std::cout << "\n";
        }
    }
    return 0;
}