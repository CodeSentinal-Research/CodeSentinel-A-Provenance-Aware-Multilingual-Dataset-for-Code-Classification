#include <iostream>
#include <vector>
#include <algorithm>
void subsets_with_dup(const std::vector<int>& nums, int idx, std::vector<int>& cur) {
    for (size_t i = 0; i < cur.size(); i++) {
        std::cout << cur[i] << (i + 1 == cur.size() ? "" : " ");
    }
    std::cout << std::endl;
    for (int i = idx; i < (int)nums.size(); i++) {
        if (i > idx && nums[i] == nums[i - 1]) continue;
        cur.push_back(nums[i]);
        subsets_with_dup(nums, i + 1, cur);
        cur.pop_back();
    }
}
int main() {
    int n;
    if (std::cin >> n) {
        std::vector<int> nums(n), cur;
        for (int i = 0; i < n; i++) std::cin >> nums[i];
        std::sort(nums.begin(), nums.end());
        subsets_with_dup(nums, 0, cur);
    }
    return 0;
}