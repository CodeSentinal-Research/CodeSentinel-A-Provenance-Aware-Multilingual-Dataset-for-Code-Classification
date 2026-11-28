#include <iostream>
#include <vector>

int removeDuplicates(std::vector<int>& nums) {
    if (nums.empty()) return 0;
    int k = 1;
    for (size_t i = 1; i < nums.size(); i++) {
        if (nums[i] != nums[i - 1]) {
            nums[k++] = nums[i];
        }
    }
    return k;
}

int main() {
    int n;
    if (std::cin >> n && n > 0) {
        std::vector<int> nums(n);
        for (int i = 0; i < n; i++) std::cin >> nums[i];
        int k = removeDuplicates(nums);
        std::cout << k << "\n";
        for (int i = 0; i < k; i++) {
            std::cout << nums[i] << (i == k - 1 ? "" : " ");
        }
        std::cout << "\n";
    }
    return 0;
}