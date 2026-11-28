#include <vector>
#include <queue>
#include <climits>

class Solution {
    struct Element {
        int val, r, c;
        bool operator>(const Element& o) const { return val > o.val; }
    };
public:
    std::vector<int> smallestRange(std::vector<std::vector<int>>& nums) {
        std::priority_queue<Element, std::vector<Element>, std::greater<Element>> pq;
        int curMax = INT_MIN;
        for (int i = 0; i < (int)nums.size(); i++) {
            pq.push({nums[i][0], i, 0});
            curMax = std::max(curMax, nums[i][0]);
        }
        int start = pq.top().val, end = curMax;
        while (true) {
            auto [val, r, c] = pq.top();
            pq.pop();
            if (c + 1 == (int)nums[r].size()) break;
            int nextVal = nums[r][c + 1];
            curMax = std::max(curMax, nextVal);
            pq.push({nextVal, r, c + 1});
            if (curMax - pq.top().val < end - start) {
                start = pq.top().val;
                end = curMax;
            }
        }
        return {start, end};
    }
};