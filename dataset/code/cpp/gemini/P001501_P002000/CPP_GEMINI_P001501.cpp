#include <vector>
#include <algorithm>

class Solution {
public:
    int maxDistToClosest(std::vector<int>& seats) {
        int n = seats.size();
        int prev = -1, maxDist = 0;

        for (int i = 0; i < n; i++) {
            if (seats[i] == 1) {
                if (prev == -1) maxDist = i;
                else maxDist = std::max(maxDist, (i - prev) / 2);
                prev = i;
            }
        }
        return std::max(maxDist, n - 1 - prev);
    }
};