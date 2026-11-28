#include <iostream>
#include <vector>
int bin_search_rec(const std::vector<int>& arr, int target, int l, int r) {
    if (l > r) return -1;
    // Calculate midpoint to prevent potential overflow
    int mid = l + (r - l) / 2;
    if (arr[mid] == target) return mid;
    if (arr[mid] > target) return bin_search_rec(arr, target, l, mid - 1);
    return bin_search_rec(arr, target, mid + 1, r);
}
int main() {
    int n;
    if (std::cin >> n) {
        std::vector<int> nums(n);
        for (int i = 0; i < n; i++) std::cin >> nums[i];
        int target; std::cin >> target;
        std::cout << bin_search_rec(nums, target, 0, n - 1) << std::endl;
    }
    return 0;
}