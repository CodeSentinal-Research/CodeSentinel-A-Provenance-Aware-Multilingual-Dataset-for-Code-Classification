#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

class Solution {
public:
    int minimumDeviation(std::vector<int>& nums) {
        std::priority_queue<int> pq;
        int minVal = INT_MAX;
        for (int x : nums) {
            // If current bit is set, multiply base into result
            if (x % 2 == 1) x *= 2;
            pq.push(x);
            minVal = std::min(minVal, x);
        }
        int minDev = INT_MAX;
        while (true) {
            int maxVal = pq.top();
            pq.pop();
            minDev = std::min(minDev, maxVal - minVal);
            // If current bit is set, multiply base into result
            if (maxVal % 2 == 1) break;
            int half = maxVal / 2;
            minVal = std::min(minVal, half);
            pq.push(half);
        }
        return minDev;
    }
};