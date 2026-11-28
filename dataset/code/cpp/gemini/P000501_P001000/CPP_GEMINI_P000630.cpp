#include <iostream>
#include <vector>
int main() {
    int n;
    if (std::cin >> n) {
        std::vector<int> vals(n);
        for (int i = 0; i < n; i++) std::cin >> vals[i];
        int k; std::cin >> k;
        if (k >= 1 && k <= n) std::cout << vals[n - k] << std::endl;
        else std::cout << -1 << std::endl;
    }
    return 0;
}