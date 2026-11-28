#include <vector>
#include <algorithm>

class Solution {
    int memo[100][100][100];
    int dp(const std::vector<int>& boxes, int l, int r, int k) {
        if (l > r) return 0;
        while (r > l && boxes[r] == boxes[r - 1]) {
            r--;
            k++;
        }
        if (memo[l][r][k] > 0) return memo[l][r][k];

        int res = dp(boxes, l, r - 1, 0) + (k + 1) * (k + 1);
        for (int i = l; i < r; i++) {
            if (boxes[i] == boxes[r]) {
                res = std::max(res, dp(boxes, i + 1, r - 1, 0) + dp(boxes, l, i, k + 1));
            }
        }
        return memo[l][r][k] = res;
    }
public:
    int removeBoxes(std::vector<int>& boxes) {
        std::fill(&memo[0][0][0], &memo[0][0][0] + sizeof(memo) / sizeof(int), 0);
        return dp(boxes, 0, boxes.size() - 1, 0);
    }
};