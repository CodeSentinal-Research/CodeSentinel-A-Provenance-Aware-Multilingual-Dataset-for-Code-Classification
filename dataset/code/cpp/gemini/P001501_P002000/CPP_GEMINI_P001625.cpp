#include <iostream>
#include <vector>

int main() {
    int m, n;
    if (std::cin >> m >> n) {
        std::vector<std::vector<long long>> p(m, std::vector<long long>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                std::cin >> p[i][j];
                if (i > 0) p[i][j] += p[i - 1][j];
                if (j > 0) p[i][j] += p[i][j - 1];
                if (i > 0 && j > 0) p[i][j] -= p[i - 1][j - 1];
                std::cout << p[i][j] << (j == n - 1 ? "" : " ");
            }
            std::cout << "\n";
        }
    }
    return 0;
}