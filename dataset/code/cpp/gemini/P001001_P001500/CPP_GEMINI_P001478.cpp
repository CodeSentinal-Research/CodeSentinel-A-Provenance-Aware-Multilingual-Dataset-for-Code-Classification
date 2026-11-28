#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> intervalIntersection(std::vector<std::vector<int>>& firstList, std::vector<std::vector<int>>& secondList) {
        std::vector<std::vector<int>> res;
        size_t i = 0, j = 0;

        while (i < firstList.size() && j < secondList.size()) {
            int lo = std::max(firstList[i][0], secondList[j][0]);
            int hi = std::min(firstList[i][1], secondList[j][1]);

            if (lo <= hi) {
                res.push_back({lo, hi});
            }

            if (firstList[i][1] < secondList[j][1]) {
                i++;
            } else {
                j++;
            }
        }
        return res;
    }
};