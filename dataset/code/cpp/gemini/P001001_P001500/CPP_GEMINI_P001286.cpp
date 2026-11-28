#include <vector>
#include <algorithm>

class Solution {
public:
    int maximumBags(std::vector<int>& capacity, std::vector<int>& rocks, int additionalRocks) {
        int n = capacity.size();
        std::vector<int> remaining(n);
        for (int i = 0; i < n; i++) remaining[i] = capacity[i] - rocks[i];
        std::sort(remaining.begin(), remaining.end());

        int fullBags = 0;
        for (int rem : remaining) {
            if (additionalRocks >= rem) {
                additionalRocks -= rem;
                fullBags++;
            } else {
                break;
            }
        }
        return fullBags;
    }
};