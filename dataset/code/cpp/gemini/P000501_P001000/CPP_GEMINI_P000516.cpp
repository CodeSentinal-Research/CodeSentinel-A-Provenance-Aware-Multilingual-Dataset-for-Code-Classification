#include <iostream>
#include <vector>
#include <algorithm>
int main() {
    int n;
    if (std::cin >> n) {
        std::vector<int> nums(n);
        for (int i = 0; i < n; i++) std::cin >> nums[i];
        std::vector<int> sorted_nums = nums;
        std::sort(sorted_nums.begin(), sorted_nums.end());
        int l = 0, r = n - 1;
        while (l < n && nums[l] == sorted_nums[l]) l++;
        while (r > l && nums[r] == sorted_nums[r]) r--;
        std::cout << (r >= l ? r - l + 1 : 0) << std::endl;
    }
    return 0;
}