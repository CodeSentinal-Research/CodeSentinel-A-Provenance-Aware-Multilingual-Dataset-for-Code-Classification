#include <iostream>
#include <vector>
#include <algorithm>
void find_all_subseq(const std::vector<int>& arr, int idx, std::vector<int>& cur, int cur_sum, int target, std::vector<std::vector<int>>& res) {
    if (idx == (int)arr.size()) {
        if (cur_sum == target && !cur.empty()) res.push_back(cur);
        return;
    }
    find_all_subseq(arr, idx + 1, cur, cur_sum, target, res);
    cur.push_back(arr[idx]);
    find_all_subseq(arr, idx + 1, cur, cur_sum + arr[idx], target, res);
    cur.pop_back();
}
int main() {
    int n;
    if (std::cin >> n) {
        std::vector<int> nums(n), cur;
        for (int i = 0; i < n; i++) std::cin >> nums[i];
        int target; std::cin >> target;
        std::vector<std::vector<int>> res;
        find_all_subseq(nums, 0, cur, 0, target, res);
        std::sort(res.begin(), res.end());
        for (const auto& seq : res) {
            for (size_t i = 0; i < seq.size(); i++) {
                std::cout << seq[i] << (i + 1 == seq.size() ? "" : " ");
            }
            std::cout << std::endl;
        }
    }
    return 0;
}