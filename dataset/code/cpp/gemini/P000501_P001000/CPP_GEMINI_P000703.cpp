#include <iostream>
#include <vector>
bool is_pal(const std::vector<int>& arr, int l, int r) {
    if (l >= r) return true;
    if (arr[l] != arr[r]) return false;
    return is_pal(arr, l + 1, r - 1);
}
int main() {
    int n;
    if (std::cin >> n) {
        std::vector<int> nums(n);
        for (int i = 0; i < n; i++) std::cin >> nums[i];
        std::cout << (is_pal(nums, 0, n - 1) ? "true" : "false") << std::endl;
    }
    return 0;
}