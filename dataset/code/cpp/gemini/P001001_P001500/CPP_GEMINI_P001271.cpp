#include <vector>
#include <algorithm>

class Solution {
public:
    int minTaps(int n, std::vector<int>& ranges) {
        std::vector<int> maxReach(n + 1, 0);
        for (int i = 0; i <= n; i++) {
            int left = std::max(0, i - ranges[i]);
            int right = std::min(n, i + ranges[i]);
            maxReach[left] = std::max(maxReach[left], right);
        }

        int taps = 0, curEnd = 0, nextEnd = 0;
        for (int i = 0; i < n; i++) {
            nextEnd = std::max(nextEnd, maxReach[i]);
            if (i == curEnd) {
                if (nextEnd <= i) return -1;
                taps++;
                curEnd = nextEnd;
            }
        }
        return taps;
    }
};