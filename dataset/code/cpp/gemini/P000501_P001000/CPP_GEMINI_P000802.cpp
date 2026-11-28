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
        long long threshold; std::cin >> threshold;
        int max_len = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                while (i + max_len < n && j + max_len < m) {
                    long long sum = pref[i + max_len + 1][j + max_len + 1] - pref[i][j + max_len + 1] - pref[i + max_len + 1][j] + pref[i][j];
                    if (sum <= threshold) max_len++;
                    else break;
                }
            }
        }
        std::cout << max_len << std::endl;
    }
    return 0;
}