#include <vector>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    int leastBricks(std::vector<std::vector<int>>& wall) {
        std::unordered_map<int, int> map;
        int maxGaps = 0;

        for (const auto& row : wall) {
            int edge = 0;
            for (size_t i = 0; i + 1 < row.size(); i++) {
                edge += row[i];
                maxGaps = std::max(maxGaps, ++map[edge]);
            }
        }
        return (int)wall.size() - maxGaps;
    }
};