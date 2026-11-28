#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, k;
    if (std::cin >> n >> k) {
        std::vector<int> nums(n);
        for (int i = 0; i < n; i++) std::cin >> nums[i];
        int maxVal = *std::max_element(nums.begin(), nums.begin() + k);
        std::cout << maxVal << "\n";
    }
    return 0;
}