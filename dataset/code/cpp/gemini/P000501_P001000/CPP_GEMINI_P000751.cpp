#include <iostream>
#include <vector>
long long count_subseq_sum(const std::vector<int>& arr, int idx, int cur_sum, int target) {
    if (idx == (int)arr.size()) {
        return (cur_sum == target ? 1 : 0);
    }
    return count_subseq_sum(arr, idx + 1, cur_sum, target) + count_subseq_sum(arr, idx + 1, cur_sum + arr[idx], target);
}
int main() {
    int n;
    if (std::cin >> n) {
        std::vector<int> nums(n);
        for (int i = 0; i < n; i++) std::cin >> nums[i];
        int target; std::cin >> target;
        std::cout << count_subseq_sum(nums, 0, 0, target) << std::endl;
    }
    return 0;
}