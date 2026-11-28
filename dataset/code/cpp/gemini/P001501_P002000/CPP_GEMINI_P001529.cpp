#include <iostream>
#include <vector>
#include <unordered_map>

long long atMost(const std::vector<int>& nums, int k) {
    std::unordered_map<int, int> count;
    int l = 0;
    long long ans = 0;

    for (size_t r = 0; r < nums.size(); r++) {
        count[nums[r]]++;
        while ((int)count.size() > k) {
            if (--count[nums[l]] == 0) count.erase(nums[l]);
            l++;
        }
        ans += r - l + 1;
    }
    return ans;
}

int main() {
    int n, k;
    if (std::cin >> n >> k) {
        std::vector<int> nums(n);
        for (int i = 0; i < n; i++) std::cin >> nums[i];
        std::cout << atMost(nums, k) - atMost(nums, k - 1) << "\n";
    }
    return 0;
}