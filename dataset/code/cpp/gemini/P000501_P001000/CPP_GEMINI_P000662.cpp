#include <iostream>
#include <vector>
#include <algorithm>
int main() {
    int n;
    if (std::cin >> n) {
        std::vector<int> vals(n);
        for (int i = 0; i < n; i++) std::cin >> vals[i];
        int k; std::cin >> k;
        k = std::min(k, n);
        std::reverse(vals.begin(), vals.begin() + k);
        for (int i = 0; i < n; i++) std::cout << vals[i] << (i == n - 1 ? "" : " ");
        std::cout << std::endl;
    }
    return 0;
}