#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
void find_subseq(const std::vector<int>& nums, int idx, std::vector<int>& cur, std::set<std::vector<int>>& res) {
    if (cur.size() >= 2) res.insert(cur);
    for (int i = idx; i < (int)nums.size(); i++) {
        if (cur.empty() || nums[i] >= cur.back()) {
            cur.push_back(nums[i]);
            find_subseq(nums, i + 1, cur, res);
            cur.pop_back();
        }
    }
}
int main() {
    int n;
    if (std::cin >> n) {
        std::vector<int> nums(n), cur;
        for (int i = 0; i < n; i++) std::cin >> nums[i];
        std::set<std::vector<int>> res;
        find_subseq(nums, 0, cur, res);
        for (const auto& seq : res) {
            for (size_t i = 0; i < seq.size(); i++) {
                std::cout << seq[i] << (i + 1 == seq.size() ? "" : " ");
            }
            std::cout << std::endl;
        }
    }
    return 0;
}