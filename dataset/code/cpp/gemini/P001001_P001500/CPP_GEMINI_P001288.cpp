#include <vector>
#include <queue>
#include <numeric>

class Solution {
public:
    int largestSumAfterKNegations(std::vector<int>& nums, int k) {
        std::priority_queue<int, std::vector<int>, std::greater<int>> pq(nums.begin(), nums.end());
        for (int i = 0; i < k; i++) {
            int top = pq.top();
            pq.pop();
            pq.push(-top);
        }
        int sum = 0;
        while (!pq.empty()) {
            sum += pq.top();
            pq.pop();
        }
        return sum;
    }
};