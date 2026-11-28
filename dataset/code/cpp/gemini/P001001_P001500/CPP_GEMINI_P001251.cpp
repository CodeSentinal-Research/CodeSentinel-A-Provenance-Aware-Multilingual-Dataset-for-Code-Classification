#include <vector>
#include <algorithm>

class Solution {
public:
    int maximumUnits(std::vector<std::vector<int>>& boxTypes, int truckSize) {
        std::sort(boxTypes.begin(), boxTypes.end(), [](const auto& a, const auto& b) {
            return a[1] > b[1];
        });
        int totalUnits = 0;

        for (const auto& box : boxTypes) {
            int take = std::min(truckSize, box[0]);
            totalUnits += take * box[1];
            truckSize -= take;
            if (truckSize == 0) break;
        }
        return totalUnits;
    }
};