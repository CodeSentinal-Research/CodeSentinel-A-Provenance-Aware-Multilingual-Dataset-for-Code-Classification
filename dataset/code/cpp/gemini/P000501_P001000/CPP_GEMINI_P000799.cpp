#include <iostream>
#include <vector>
int main() {
    int n, m;
    if (std::cin >> n >> m) {
        std::vector<std::vector<long long>> pref(n, std::vector<long long>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                long long x; std::cin >> x;
                pref[i][j] = x;
                if (i > 0) pref[i][j] += pref[i - 1][j];
                if (j > 0) pref[i][j] += pref[i][j - 1];
                if (i > 0 && j > 0) pref[i][j] -= pref[i - 1][j - 1];
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                std::cout << pref[i][j] << (j == m - 1 ? "" : " ");
            }
            std::cout << std::endl;
        }
    }
    return 0;
}