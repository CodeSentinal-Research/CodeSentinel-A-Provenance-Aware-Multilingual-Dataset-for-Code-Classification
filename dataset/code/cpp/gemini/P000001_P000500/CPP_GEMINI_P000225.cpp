#include <vector>
#include <algorithm>

class Solution {
public:
    int minSwaps(std::vector<int>& nums) {
        int n = nums.size();
        std::vector<std::pair<int, int>> arrPos(n);
        for (int i = 0; i < n; i++) arrPos[i] = {nums[i], i};
        std::sort(arrPos.begin(), arrPos.end());

        std::vector<bool> visited(n, false);
        int swaps = 0;

        for (int i = 0; i < n; i++) {
            if (visited[i] || arrPos[i].second == i) continue;

            int cycleSize = 0;
            int j = i;
            while (!visited[j]) {
                visited[j] = true;
                j = arrPos[j].second;
                cycleSize++;
            }

            if (cycleSize > 0) swaps += cycleSize - 1;
        }
        return swaps;
    }
};