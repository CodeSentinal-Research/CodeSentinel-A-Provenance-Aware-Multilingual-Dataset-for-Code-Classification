#include <vector>
#include <algorithm>

class Solution {
public:
    int twoCitySchedCost(std::vector<std::vector<int>>& costs) {
        std::sort(costs.begin(), costs.end(), [](const auto& a, const auto& b) {
            return (a[0] - a[1]) < (b[0] - b[1]);
        });
        int n = costs.size() / 2;
        int total = 0;

        for (int i = 0; i < n; i++) {
            total += costs[i][0] + costs[i + n][1];
        }
        return total;
    }
};