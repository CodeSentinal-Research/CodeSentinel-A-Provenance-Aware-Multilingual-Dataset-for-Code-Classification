#include <iostream>
#include <vector>
bool lin_search_rec(const std::vector<int>& arr, int target, int idx) {
    if (idx >= (int)arr.size()) return false;
    if (arr[idx] == target) return true;
    return lin_search_rec(arr, target, idx + 1);
}
int main() {
    int n;
    if (std::cin >> n) {
        std::vector<int> nums(n);
        for (int i = 0; i < n; i++) std::cin >> nums[i];
        int target; std::cin >> target;
        std::cout << (lin_search_rec(nums, target, 0) ? "true" : "false") << std::endl;
    }
    return 0;
}