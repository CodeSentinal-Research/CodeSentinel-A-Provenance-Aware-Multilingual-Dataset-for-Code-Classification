#include <iostream>
#include <vector>
bool is_max_heap(const std::vector<int>& arr, int idx) {
    int n = arr.size();
    int l = 2 * idx + 1, r = 2 * idx + 2;
    if (l < n) {
        if (arr[idx] < arr[l] || !is_max_heap(arr, l)) return false;
    }
    if (r < n) {
        if (arr[idx] < arr[r] || !is_max_heap(arr, r)) return false;
    }
    return true;
}
int main() {
    int n;
    if (std::cin >> n) {
        std::vector<int> nums(n);
        for (int i = 0; i < n; i++) std::cin >> nums[i];
        std::cout << (is_max_heap(nums, 0) ? "true" : "false") << std::endl;
    }
    return 0;
}