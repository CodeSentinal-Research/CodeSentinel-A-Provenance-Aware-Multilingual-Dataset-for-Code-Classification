#include <iostream>
#include <vector>
int count_occ_rec(const std::vector<int>& arr, int target, int idx) {
    if (idx >= (int)arr.size()) return 0;
    return (arr[idx] == target ? 1 : 0) + count_occ_rec(arr, target, idx + 1);
}
int main() {
    int n;
    if (std::cin >> n) {
        std::vector<int> nums(n);
        for (int i = 0; i < n; i++) std::cin >> nums[i];
        int target; std::cin >> target;
        std::cout << count_occ_rec(nums, target, 0) << std::endl;
    }
    return 0;
}