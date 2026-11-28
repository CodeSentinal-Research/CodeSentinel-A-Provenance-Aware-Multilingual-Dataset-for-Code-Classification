#include <iostream>
#include <vector>
#include <algorithm>
int main() {
    int m, n;
    if (std::cin >> m >> n) {
        std::vector<long long> res(m + n);
        for (int i = 0; i < m + n; i++) std::cin >> res[i];
        std::sort(res.begin(), res.end());
        for (int i = 0; i < m + n; i++) {
            if (i > 0) std::cout << " ";
            std::cout << res[i];
        }
        std::cout << std::endl;
    }
    return 0;
}