#include <vector>
#include <queue>

class Solution {
public:
    std::vector<int> maxSlidingWindow(std::vector<int>& nums, int k) {
        std::priority_queue<std::pair<int, int>> pq;
        std::vector<int> res;
        for (int i = 0; i < (int)nums.size(); i++) {
            pq.push({nums[i], i});
            if (i >= k - 1) {
                while (pq.top().second <= i - k) pq.pop();
                res.push_back(pq.top().first);
            }
        }
        return res;
    }
};