#include <iostream>
#include <vector>
#include <algorithm>
int main() {
    int n;
    if (std::cin >> n) {
        std::vector<int> vals(n);
        for (int i = 0; i < n; i++) std::cin >> vals[i];
        int max_sum = 0;
        for (int i = 0; i < n / 2; i++) {
            max_sum = std::max(max_sum, vals[i] + vals[n - 1 - i]);
        }
        std::cout << max_sum << std::endl;
    }
    return 0;
}