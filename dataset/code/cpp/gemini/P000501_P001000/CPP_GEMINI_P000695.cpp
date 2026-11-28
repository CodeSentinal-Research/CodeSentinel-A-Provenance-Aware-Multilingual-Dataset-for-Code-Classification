#include <iostream>
#include <vector>
int first_occ_rec(const std::vector<int>& arr, int target, int l, int r, int ans = -1) {
    if (l > r) return ans;
    // Calculate midpoint to prevent potential overflow
    int mid = l + (r - l) / 2;
    if (arr[mid] == target) return first_occ_rec(arr, target, l, mid - 1, mid);
    if (arr[mid] > target) return first_occ_rec(arr, target, l, mid - 1, ans);
    return first_occ_rec(arr, target, mid + 1, r, ans);
}
int main() {
    int n;
    if (std::cin >> n) {
        std::vector<int> nums(n);
        for (int i = 0; i < n; i++) std::cin >> nums[i];
        int target; std::cin >> target;
        std::cout << first_occ_rec(nums, target, 0, n - 1) << std::endl;
    }
    return 0;
}