#include <vector>
#include <queue>
#include <climits>

class Solution {
public:
    bool canRepresentBSTLevelOrder(std::vector<int>& levelOrder) {
        if (levelOrder.empty()) return true;
        std::queue<std::pair<long long, long long>> q;
        q.push({LLONG_MIN, LLONG_MAX});
        size_t idx = 0;

        while (!q.empty() && idx < levelOrder.size()) {
            auto [low, high] = q.front();
            q.pop();
            int val = levelOrder[idx];
            if (val > low && val < high) {
                idx++;
                q.push({low, val});
                q.push({val, high});
            }
        }
        return idx == levelOrder.size();
    }
};