#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

int main() {
    int n, m;
    if (std::cin >> n >> m) {
        std::vector<std::vector<bool>> adj1(n, std::vector<bool>(n, false));
        for (int i = 0; i < m; i++) {
            int u, v;
            std::cin >> u >> v;
            adj1[u][v] = adj1[v][u] = true;
        }
        std::vector<std::vector<bool>> adj2(n, std::vector<bool>(n, false));
        for (int i = 0; i < m; i++) {
            int u, v;
            std::cin >> u >> v;
            adj2[u][v] = adj2[v][u] = true;
        }
        std::vector<int> p(n);
        std::iota(p.begin(), p.end(), 0);
        bool isomorphic = false;
        do {
            bool ok = true;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (adj1[i][j] != adj2[p[i]][p[j]]) {
                        ok = false;
                        break;
                    }
                }
                if (!ok) break;
            }
            if (ok) {
                isomorphic = true;
                break;
            }
        } while (std::next_permutation(p.begin(), p.end()));
        std::cout << (isomorphic ? "YES" : "NO") << "\n";
    }
    return 0;
}