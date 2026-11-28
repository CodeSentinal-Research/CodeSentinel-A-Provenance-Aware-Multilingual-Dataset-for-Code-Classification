#include <iostream>
#include <vector>
void ins_sort_rec(std::vector<int>& arr, int n) {
    if (n <= 1) return;
    ins_sort_rec(arr, n - 1);
    int last = arr[n - 1];
    int j = n - 2;
    while (j >= 0 && arr[j] > last) {
        arr[j + 1] = arr[j];
        j--;
    }
    arr[j + 1] = last;
}
int main() {
    int n;
    if (std::cin >> n) {
        std::vector<int> nums(n);
        for (int i = 0; i < n; i++) std::cin >> nums[i];
        ins_sort_rec(nums, n);
        for (int i = 0; i < n; i++) std::cout << nums[i] << (i == n - 1 ? "" : " ");
        std::cout << std::endl;
    }
    return 0;
}