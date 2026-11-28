#include <iostream>
#include <vector>
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
        int q; std::cin >> q;
        while (q--) {
            int r1, c1, r2, c2;
            std::cin >> r1 >> c1 >> r2 >> c2;
            long long ans = pref[r2 + 1][c2 + 1] - pref[r1][c2 + 1] - pref[r2 + 1][c1] + pref[r1][c1];
            std::cout << ans << std::endl;
        }
    }
    return 0;
}