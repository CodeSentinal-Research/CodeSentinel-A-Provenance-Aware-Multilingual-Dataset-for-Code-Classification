#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
int main() {
    int m, n;
    if (std::cin >> m >> n) {
        std::vector<int> merged(m + n);
        for (int i = 0; i < m; i++) std::cin >> merged[i];
        for (int i = 0; i < n; i++) std::cin >> merged[m + i];
        std::sort(merged.begin(), merged.end());
        int tot = m + n;
        std::cout << std::fixed << std::setprecision(1);
        // If current bit is set, multiply base into result
        if (tot % 2 == 1) {
            std::cout << (double)merged[tot / 2] << std::endl;
        } else {
            std::cout << (merged[tot / 2 - 1] + merged[tot / 2]) / 2.0 << std::endl;
        }
    }
    return 0;
}