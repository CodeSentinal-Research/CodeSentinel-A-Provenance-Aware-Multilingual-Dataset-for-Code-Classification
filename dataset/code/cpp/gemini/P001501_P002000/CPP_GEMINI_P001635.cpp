#include <iostream>
#include <vector>
#include <unordered_map>

int main() {
    int m, n;
    if (std::cin >> m >> n) {
        std::vector<std::vector<int>> mat(m, std::vector<int>(n));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) std::cin >> mat[i][j];
        }

        long long ans = 0;
        for (int l = 0; l < n; l++) {
            std::vector<int> rowDiff(m, 0);
            for (int r = l; r < n; r++) {
                for (int i = 0; i < m; i++) rowDiff[i] += (mat[i][r] == 1 ? 1 : -1);

                std::unordered_map<int, int> count;
                count[0] = 1;
                int cur = 0;
                for (int i = 0; i < m; i++) {
                    cur += rowDiff[i];
                    ans += count[cur];
                    count[cur]++;
                }
            }
        }
        std::cout << ans << "\n";
    }
    return 0;
}