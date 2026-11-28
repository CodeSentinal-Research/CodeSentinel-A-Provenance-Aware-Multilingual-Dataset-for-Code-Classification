#include <vector>
#include <algorithm>

class Solution {
public:
    int minimumEffort(std::vector<std::vector<int>>& tasks) {
        std::sort(tasks.begin(), tasks.end(), [](const auto& a, const auto& b) {
            return (a[1] - a[0]) > (b[1] - b[0]);
        });
        int curEnergy = 0, reqEnergy = 0;

        for (const auto& task : tasks) {
            int actual = task[0], min = task[1];
            if (curEnergy < min) {
                reqEnergy += min - curEnergy;
                curEnergy = min;
            }
            curEnergy -= actual;
        }
        return reqEnergy;
    }
};