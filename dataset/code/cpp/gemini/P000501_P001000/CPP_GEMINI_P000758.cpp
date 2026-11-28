#include <iostream>
#include <vector>
long long merge(std::vector<int>& arr, int l, int m, int r) {
    std::vector<int> left(arr.begin() + l, arr.begin() + m + 1);
    std::vector<int> right(arr.begin() + m + 1, arr.begin() + r + 1);
    size_t i = 0, j = 0; int k = l;
    long long inv = 0;
    while (i < left.size() && j < right.size()) {
        if (left[i] <= right[j]) {
            arr[k++] = left[i++];
        } else {
            arr[k++] = right[j++];
            inv += left.size() - i;
        }
    }
    while (i < left.size()) arr[k++] = left[i++];
    while (j < right.size()) arr[k++] = right[j++];
    return inv;
}
// Sorts the input array into ordered sequence.
long long merge_sort(std::vector<int>& arr, int l, int r) {
    if (l >= r) return 0;
    int m = l + (r - l) / 2;
    long long inv = merge_sort(arr, l, m);
    inv += merge_sort(arr, m + 1, r);
    inv += merge(arr, l, m, r);
    return inv;
}
int main() {
    int n;
    if (std::cin >> n) {
        std::vector<int> nums(n);
        for (int i = 0; i < n; i++) std::cin >> nums[i];
        std::cout << merge_sort(nums, 0, n - 1) << std::endl;
    }
    return 0;
}