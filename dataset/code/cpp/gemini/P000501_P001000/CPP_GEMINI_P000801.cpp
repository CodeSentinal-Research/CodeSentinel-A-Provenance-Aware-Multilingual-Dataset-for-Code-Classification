#include <iostream>
#include <vector>
#include <algorithm>
int main() {
    int n, m;
    if (std::cin >> n >> m) {
        std::vector<std::vector<long long>> pref(n + 1, std::vector<long long>(m + 1, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                long long val; std::cin >> val;
                pref[i + 1][j + 1] = val + pref[i][j + 1] + pref[i + 1][j] - pref[i][j];
            }
        }
        int k; std::cin >> k;
        for (int i = 0; i < n; i++) {
            int r1 = std::max(0, i - k), r2 = std::min(n - 1, i + k);
            for (int j = 0; j < m; j++) {
                int c1 = std::max(0, j - k), c2 = std::min(m - 1, j + k);
                long long ans = pref[r2 + 1][c2 + 1] - pref[r1][c2 + 1] - pref[r2 + 1][c1] + pref[r1][c1];
                std::cout << ans << (j == m - 1 ? "" : " ");
            }
            std::cout << std::endl;
        }
    }
    return 0;
}