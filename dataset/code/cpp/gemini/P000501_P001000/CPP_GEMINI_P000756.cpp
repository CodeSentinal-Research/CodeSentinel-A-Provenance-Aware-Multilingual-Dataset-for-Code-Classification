#include <iostream>
#include <vector>
#include <algorithm>
void quick_sort(std::vector<int>& arr, int l, int r) {
    if (l >= r) return;
    int pivot = arr[r], p_idx = l;
    for (int i = l; i < r; i++) {
        if (arr[i] < pivot) std::swap(arr[i], arr[p_idx++]);
    }
    std::swap(arr[p_idx], arr[r]);
    quick_sort(arr, l, p_idx - 1);
    quick_sort(arr, p_idx + 1, r);
}
int main() {
    int n;
    if (std::cin >> n) {
        std::vector<int> nums(n);
        for (int i = 0; i < n; i++) std::cin >> nums[i];
        quick_sort(nums, 0, n - 1);
        for (int i = 0; i < n; i++) std::cout << nums[i] << (i == n - 1 ? "" : " ");
        std::cout << std::endl;
    }
    return 0;
}