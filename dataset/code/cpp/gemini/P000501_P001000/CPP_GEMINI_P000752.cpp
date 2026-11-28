#include <iostream>
#include <vector>
bool find_one_subseq(const std::vector<int>& arr, int idx, std::vector<int>& cur, int cur_sum, int target) {
    if (idx == (int)arr.size()) {
        if (cur_sum == target && !cur.empty()) {
            for (size_t i = 0; i < cur.size(); i++) {
                std::cout << cur[i] << (i + 1 == cur.size() ? "" : " ");
            }
            std::cout << std::endl;
            return true;
        }
        return false;
    }
    cur.push_back(arr[idx]);
    if (find_one_subseq(arr, idx + 1, cur, cur_sum + arr[idx], target)) return true;
    cur.pop_back();
    if (find_one_subseq(arr, idx + 1, cur, cur_sum, target)) return true;
    return false;
}
int main() {
    int n;
    if (std::cin >> n) {
        std::vector<int> nums(n), cur;
        for (int i = 0; i < n; i++) std::cin >> nums[i];
        int target; std::cin >> target;
        if (!find_one_subseq(nums, 0, cur, 0, target)) {
            std::cout << -1 << std::endl;
        }
    }
    return 0;
}