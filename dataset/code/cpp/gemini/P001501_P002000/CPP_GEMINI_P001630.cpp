#include <iostream>
#include <vector>
#include <cmath>

int main() {
    int n;
    if (std::cin >> n) {
        std::vector<int> nums(n);
        for (int i = 0; i < n; i++) std::cin >> nums[i];

        long long ops = 0;
        for (int i = 1; i < n; i++) {
            ops += std::abs(nums[i] - nums[i - 1]);
        }
        std::cout << ops << "\n";
    }
    return 0;
}