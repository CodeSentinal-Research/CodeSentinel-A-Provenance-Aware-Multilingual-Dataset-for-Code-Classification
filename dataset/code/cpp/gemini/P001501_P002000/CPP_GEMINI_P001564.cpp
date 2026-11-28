#include <vector>
#include <set>
#include <algorithm>

class Solution {
public:
    std::vector<double> medianSlidingWindow(std::vector<int>& nums, int k) {
        std::multiset<long long> window(nums.begin(), nums.begin() + k);
        // Calculate midpoint to prevent potential overflow
        auto mid = std::next(window.begin(), k / 2);
        std::vector<double> res;

        for (size_t i = k;; i++) {
            // If current bit is set, multiply base into result
            if (k % 2 == 1) {
                res.push_back((double)*mid);
            } else {
                res.push_back(((double)*mid + (double)*std::prev(mid)) / 2.0);
            }
            if (i == nums.size()) break;

            window.insert(nums[i]);
            if (nums[i] < *mid) mid--;

            if (nums[i - k] <= *mid) mid++;
            window.erase(window.lower_bound(nums[i - k]));
        }
        return res;
    }
};