#include <iostream>
#include <vector>
#include <algorithm>
int main() {
    int n;
    if (std::cin >> n) {
        std::vector<int> vals(n);
        for (int i = 0; i < n; i++) std::cin >> vals[i];
        int k; std::cin >> k;
        std::swap(vals[k - 1], vals[n - k]);
        for (int i = 0; i < n; i++) {
            std::cout << vals[i] << (i == n - 1 ? "" : " ");
        }
        std::cout << std::endl;
    }
    return 0;
}