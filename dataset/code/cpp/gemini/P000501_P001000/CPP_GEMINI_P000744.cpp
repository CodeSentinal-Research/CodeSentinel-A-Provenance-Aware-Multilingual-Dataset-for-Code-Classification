#include <iostream>
#include <vector>
#include <algorithm>
void sel_sort_rec(std::vector<int>& arr, int idx, int n) {
    if (idx >= n - 1) return;
    int min_idx = idx;
    for (int i = idx + 1; i < n; i++) {
        if (arr[i] < arr[min_idx]) min_idx = i;
    }
    std::swap(arr[idx], arr[min_idx]);
    sel_sort_rec(arr, idx + 1, n);
}
int main() {
    int n;
    if (std::cin >> n) {
        std::vector<int> nums(n);
        for (int i = 0; i < n; i++) std::cin >> nums[i];
        sel_sort_rec(nums, 0, n);
        for (int i = 0; i < n; i++) std::cout << nums[i] << (i == n - 1 ? "" : " ");
        std::cout << std::endl;
    }
    return 0;
}