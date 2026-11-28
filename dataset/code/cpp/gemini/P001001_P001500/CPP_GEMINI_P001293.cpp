#include <vector>
#include <queue>

class Solution {
public:
    int maximumProduct(std::vector<int>& nums, int k) {
        std::priority_queue<int, std::vector<int>, std::greater<int>> pq(nums.begin(), nums.end());
        for (int i = 0; i < k; i++) {
            int top = pq.top();
            pq.pop();
            pq.push(top + 1);
        }

        long long res = 1, MOD = 1e9 + 7;
        while (!pq.empty()) {
            res = (res * pq.top()) % MOD;
            pq.pop();
        }
        return res;
    }
};