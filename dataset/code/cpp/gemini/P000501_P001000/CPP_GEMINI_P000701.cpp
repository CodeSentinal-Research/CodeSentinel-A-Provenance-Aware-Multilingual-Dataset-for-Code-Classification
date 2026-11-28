#include <iostream>
#include <vector>
#include <algorithm>
int min_rec(const std::vector<int>& arr, int idx) {
    if (idx == (int)arr.size() - 1) return arr[idx];
    return std::min(arr[idx], min_rec(arr, idx + 1));
}
int main() {
    int n;
    if (std::cin >> n) {
        std::vector<int> nums(n);
        for (int i = 0; i < n; i++) std::cin >> nums[i];
        std::cout << min_rec(nums, 0) << std::endl;
    }
    return 0;
}