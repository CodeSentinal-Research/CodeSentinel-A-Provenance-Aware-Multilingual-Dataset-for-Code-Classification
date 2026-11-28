#include <iostream>
#include <vector>

int main() {
    int n, l, r;
    if (std::cin >> n >> l >> r) {
        std::vector<int> nums(n);
        for (int i = 0; i < n; i++) std::cin >> nums[i];

        long long sum = 0;
        for (int i = l; i <= r; i += 2) sum += nums[i];
        std::cout << sum << "\n";
    }
    return 0;
}