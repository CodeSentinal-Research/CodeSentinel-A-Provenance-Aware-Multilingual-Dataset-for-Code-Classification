#include <vector>
#include <algorithm>

class Solution {
public:
    int maxDistToClosest(std::vector<int>& seats) {
        int n = seats.size();
        int lastPerson = -1, maxDist = 0;

        for (int i = 0; i < n; i++) {
            if (seats[i] == 1) {
                if (lastPerson == -1) {
                    maxDist = i;
                } else {
                    maxDist = std::max(maxDist, (i - lastPerson) / 2);
                }
                lastPerson = i;
            }
        }
        maxDist = std::max(maxDist, n - 1 - lastPerson);
        return maxDist;
    }
};