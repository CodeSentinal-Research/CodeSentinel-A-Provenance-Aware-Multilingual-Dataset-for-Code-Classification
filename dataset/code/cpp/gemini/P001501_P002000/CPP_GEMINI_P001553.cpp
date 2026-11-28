#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

int main() {
    int n, k;
    if (std::cin >> n >> k) {
        std::vector<int> nums(n);
        for (int i = 0; i < n; i++) std::cin >> nums[i];

        std::unordered_map<int, int> count;
        int l = 0, maxLen = 0;

        for (int r = 0; r < n; r++) {
            count[nums[r]]++;
            while ((int)count.size() > k) {
                if (--count[nums[l]] == 0) count.erase(nums[l]);
                l++;
            }
            maxLen = std::max(maxLen, r - l + 1);
        }
        std::cout << maxLen << "\n";
    }
    return 0;
}