#include <vector>
#include <algorithm>
#include <cmath>

class Solution {
public:
    int findRadius(std::vector<int>& houses, std::vector<int>& heaters) {
        std::sort(houses.begin(), houses.end());
        std::sort(heaters.begin(), heaters.end());
        int maxR = 0;
        int i = 0;
        for (int h : houses) {
            while (i + 1 < (int)heaters.size() && std::abs(heaters[i + 1] - h) <= std::abs(heaters[i] - h)) {
                i++;
            }
            maxR = std::max(maxR, std::abs(heaters[i] - h));
        }
        return maxR;
    }
};