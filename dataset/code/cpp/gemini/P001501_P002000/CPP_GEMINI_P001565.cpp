#include <vector>
#include <deque>

class Solution {
public:
    std::vector<int> maxSlidingWindow(std::vector<int>& nums, int k) {
        std::deque<int> dq;
        std::vector<int> res;

        for (size_t i = 0; i < nums.size(); i++) {
            while (!dq.empty() && nums[dq.back()] <= nums[i]) dq.pop_back();
            dq.push_back(i);

            while (dq.front() <= (int)i - k) dq.pop_front();

            if ((int)i >= k - 1) {
                res.push_back(nums[dq.front()]);
            }
        }
        return res;
    }
};