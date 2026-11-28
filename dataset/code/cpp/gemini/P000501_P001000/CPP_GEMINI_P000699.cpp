#include <iostream>
#include <vector>
#include <algorithm>
void rev_arr_rec(std::vector<int>& arr, int l, int r) {
    if (l >= r) return;
    std::swap(arr[l], arr[r]);
    rev_arr_rec(arr, l + 1, r - 1);
}
int main() {
    int n;
    if (std::cin >> n) {
        std::vector<int> nums(n);
        for (int i = 0; i < n; i++) std::cin >> nums[i];
        rev_arr_rec(nums, 0, n - 1);
        for (size_t i = 0; i < nums.size(); i++) {
            std::cout << nums[i] << (i + 1 == nums.size() ? "" : " ");
        }
        std::cout << std::endl;
    }
    return 0;
}