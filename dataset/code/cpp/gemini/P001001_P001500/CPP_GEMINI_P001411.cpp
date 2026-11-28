#include <vector>
#include <map>
#include <set>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> findWinners(std::vector<std::vector<int>>& matches) {
        std::map<int, int> losses;
        for (const auto& m : matches) {
            if (!losses.count(m[0])) losses[m[0]] = 0;
            losses[m[1]]++;
        }

        std::vector<int> zeroLoss, oneLoss;
        for (const auto& [p, l] : losses) {
            if (l == 0) zeroLoss.push_back(p);
            else if (l == 1) oneLoss.push_back(p);
        }
        return {zeroLoss, oneLoss};
    }
};