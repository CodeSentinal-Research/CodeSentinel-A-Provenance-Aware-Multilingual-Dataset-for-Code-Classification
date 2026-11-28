#include <iostream>
#include <vector>
bool is_sorted_rec(const std::vector<int>& arr, int idx) {
    if (idx >= (int)arr.size() - 1) return true;
    if (arr[idx] > arr[idx + 1]) return false;
    return is_sorted_rec(arr, idx + 1);
}
int main() {
    int n;
    if (std::cin >> n) {
        std::vector<int> nums(n);
        for (int i = 0; i < n; i++) std::cin >> nums[i];
        std::cout << (is_sorted_rec(nums, 0) ? "true" : "false") << std::endl;
    }
    return 0;
}