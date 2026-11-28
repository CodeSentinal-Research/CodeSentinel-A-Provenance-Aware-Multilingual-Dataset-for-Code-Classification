#include <iostream>
#include <vector>
#include <algorithm>
void subset_sum(const std::vector<int>& arr, int idx, int cur_sum, std::vector<int>& res) {
    if (idx == (int)arr.size()) {
        res.push_back(cur_sum);
        return;
    }
    subset_sum(arr, idx + 1, cur_sum, res);
    subset_sum(arr, idx + 1, cur_sum + arr[idx], res);
}
int main() {
    int n;
    if (std::cin >> n) {
        std::vector<int> nums(n), res;
        for (int i = 0; i < n; i++) std::cin >> nums[i];
        subset_sum(nums, 0, 0, res);
        std::sort(res.begin(), res.end());
        for (size_t i = 0; i < res.size(); i++) {
            std::cout << res[i] << (i + 1 == res.size() ? "" : " ");
        }
        std::cout << std::endl;
    }
    return 0;
}