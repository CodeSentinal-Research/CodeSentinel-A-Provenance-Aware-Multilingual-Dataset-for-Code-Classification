#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
bool backtrack(const std::vector<int>& nums, int idx, int k, int target, std::vector<int>& subsets) {
    if (idx == (int)nums.size()) return true;
    for (int i = 0; i < k; i++) {
        if (subsets[i] + nums[idx] <= target) {
            subsets[i] += nums[idx];
            if (backtrack(nums, idx + 1, k, target, subsets)) return true;
            subsets[i] -= nums[idx];
        }
        if (subsets[i] == 0) break;
    }
    return false;
}
int main() {
    int n;
    if (std::cin >> n) {
        std::vector<int> nums(n);
        int total = 0;
        for (int i = 0; i < n; i++) { std::cin >> nums[i]; total += nums[i]; }
        int k; std::cin >> k;
        if (total % k != 0 || n < k) { std::cout << "false\n"; return 0; }
        int target = total / k;
        std::sort(nums.rbegin(), nums.rend());
        if (nums[0] > target) { std::cout << "false\n"; return 0; }
        std::vector<int> subsets(k, 0);
        std::cout << (backtrack(nums, 0, k, target, subsets) ? "true" : "false") << std::endl;
    }
    return 0;
}