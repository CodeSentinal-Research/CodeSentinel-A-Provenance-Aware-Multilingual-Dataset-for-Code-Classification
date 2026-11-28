#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

int main() {
    int n, k;
    if (std::cin >> n >> k) {
        std::vector<int> nums(n);
        for (int i = 0; i < n; i++) std::cin >> nums[i];

        for (int i = 0; i <= n - k; i++) {
            std::vector<int> win(nums.begin() + i, nums.begin() + i + k);
            std::sort(win.begin(), win.end());
            long long sum = 0;
            for (int a = 0; a < k; a++) {
                for (int b = a + 1; b < k; b++) {
                    sum += std::abs(win[a] - win[b]);
                }
            }
            std::cout << sum << (i == n - k ? "" : " ");
        }
        std::cout << "\n";
    }
    return 0;
}