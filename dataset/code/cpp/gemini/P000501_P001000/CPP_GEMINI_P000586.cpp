#include <iostream>
#include <vector>
#include <algorithm>
int main() {
    int n;
    if (std::cin >> n) {
        std::vector<int> vals(n);
        for (int i = 0; i < n; i++) std::cin >> vals[i];
        int k; std::cin >> k;
        for (int i = 0; i + k <= n; i += k) {
            std::reverse(vals.begin() + i, vals.begin() + i + k);
        }
        for (int i = 0; i < n; i++) {
            std::cout << vals[i] << (i == n - 1 ? "" : " ");
        }
        std::cout << std::endl;
    }
    return 0;
}