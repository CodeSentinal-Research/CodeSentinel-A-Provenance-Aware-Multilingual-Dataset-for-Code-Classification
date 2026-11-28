#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>
#include <climits>
int min_diff = INT_MAX;
std::vector<int> best_part;
void backtrack(int n, const std::vector<int>& nums, int idx, int count, int cur_sum, int total, std::vector<int>& cur_part, int half) {
    if (count == half) {
        int diff = std::abs(total - 2 * cur_sum);
        if (diff < min_diff) {
            min_diff = diff;
            best_part = cur_part;
        }
        return;
    }
    if (idx == n || (half - count) > (n - idx)) return;
    cur_part.push_back(nums[idx]);
    backtrack(n, nums, idx + 1, count + 1, cur_sum + nums[idx], total, cur_part, half);
    cur_part.pop_back();
    backtrack(n, nums, idx + 1, count, cur_sum, total, cur_part, half);
}
int main() {
    int n;
    if (std::cin >> n) {
        std::vector<int> nums(n);
        int total = 0;
        for (int i = 0; i < n; i++) { std::cin >> nums[i]; total += nums[i]; }
        std::vector<int> cur;
        backtrack(n, nums, 0, 0, 0, total, cur, n / 2);
        std::cout << min_diff << std::endl;
        for (size_t i = 0; i < best_part.size(); i++) {
            std::cout << best_part[i] << (i + 1 == best_part.size() ? "" : " ");
        }
        std::cout << std::endl;
    }
    return 0;
}