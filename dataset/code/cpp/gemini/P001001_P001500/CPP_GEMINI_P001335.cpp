#include <vector>
#include <numeric>
#include <algorithm>

class Solution {
    bool backtrack(const std::vector<int>& matchsticks, size_t idx, int side, int sides[4]) {
        if (idx == matchsticks.size()) return true;
        for (int i = 0; i < 4; i++) {
            if (sides[i] + matchsticks[idx] <= side) {
                sides[i] += matchsticks[idx];
                if (backtrack(matchsticks, idx + 1, side, sides)) return true;
                sides[i] -= matchsticks[idx];
            }
            if (sides[i] == 0) break;
        }
        return false;
    }
public:
    bool makesquare(std::vector<int>& matchsticks) {
        int total = std::accumulate(matchsticks.begin(), matchsticks.end(), 0);
        if (total % 4 != 0) return false;
        int side = total / 4;

        std::sort(matchsticks.rbegin(), matchsticks.rend());
        if (matchsticks[0] > side) return false;

        int sides[4] = {0};
        return backtrack(matchsticks, 0, side, sides);
    }
};