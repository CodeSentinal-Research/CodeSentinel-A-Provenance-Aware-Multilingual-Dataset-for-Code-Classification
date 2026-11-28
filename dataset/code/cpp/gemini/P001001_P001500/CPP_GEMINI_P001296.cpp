#include <vector>
#include <algorithm>

class Solution {
public:
    int earliestFullBloom(std::vector<int>& plantTime, std::vector<int>& growTime) {
        int n = plantTime.size();
        std::vector<std::pair<int, int>> flowers(n);
        for (int i = 0; i < n; i++) {
            flowers[i] = {growTime[i], plantTime[i]};
        }
        std::sort(flowers.rbegin(), flowers.rend());

        int curPlantTime = 0, maxBloomTime = 0;
        for (const auto& [grow, plant] : flowers) {
            curPlantTime += plant;
            maxBloomTime = std::max(maxBloomTime, curPlantTime + grow);
        }
        return maxBloomTime;
    }
};