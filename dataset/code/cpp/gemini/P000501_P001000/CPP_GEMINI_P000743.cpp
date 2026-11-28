#include <iostream>
#include <vector>
#include <algorithm>
void bubble_sort_rec(std::vector<int>& arr, int n) {
    if (n <= 1) return;
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) std::swap(arr[i], arr[i + 1]);
    }
    bubble_sort_rec(arr, n - 1);
}
int main() {
    int n;
    if (std::cin >> n) {
        std::vector<int> nums(n);
        for (int i = 0; i < n; i++) std::cin >> nums[i];
        bubble_sort_rec(nums, n);
        for (int i = 0; i < n; i++) std::cout << nums[i] << (i == n - 1 ? "" : " ");
        std::cout << std::endl;
    }
    return 0;
}