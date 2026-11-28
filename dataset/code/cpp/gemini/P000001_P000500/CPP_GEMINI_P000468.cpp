#include <iostream>
#include <vector>
#include <algorithm>
int main() {
    int m, n, k;
    if (std::cin >> m >> n >> k) {
        std::vector<int> merged(m + n);
        for (int i = 0; i < m + n; i++) std::cin >> merged[i];
        std::sort(merged.begin(), merged.end());
        std::cout << merged[k - 1] << std::endl;
    }
    return 0;
}