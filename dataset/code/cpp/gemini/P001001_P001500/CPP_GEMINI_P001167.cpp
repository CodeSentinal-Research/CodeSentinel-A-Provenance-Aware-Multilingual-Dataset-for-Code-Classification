#include <vector>
#include <algorithm>

class Solution {
public:
    int minCost(std::vector<std::vector<int>>& costs) {
        if (costs.empty()) return 0;
        int r = 0, g = 0, b = 0;
        for (const auto& c : costs) {
            int nr = c[0] + std::min(g, b);
            int ng = c[1] + std::min(r, b);
            int nb = c[2] + std::min(r, g);
            r = nr;
            g = ng;
            b = nb;
        }
        return std::min({r, g, b});
    }
};