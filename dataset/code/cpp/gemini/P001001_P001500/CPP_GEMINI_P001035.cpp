#include <vector>
#include <queue>
#include <tuple>

class Solution {
public:
    int kthSmallest(std::vector<std::vector<int>>& matrix, int k) {
        int n = matrix.size();
        std::priority_queue<std::tuple<int, int, int>, std::vector<std::tuple<int, int, int>>, std::greater<std::tuple<int, int, int>>> pq;
        for (int i = 0; i < n; i++) {
            pq.push({matrix[i][0], i, 0});
        }
        for (int i = 0; i < k - 1; i++) {
            auto [val, r, c] = pq.top();
            pq.pop();
            if (c + 1 < n) pq.push({matrix[r][c + 1], r, c + 1});
        }
        return std::get<0>(pq.top());
    }
};