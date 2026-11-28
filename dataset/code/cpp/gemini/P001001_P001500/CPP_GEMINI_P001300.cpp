#include <vector>
#include <algorithm>

class Solution {
public:
    int numRescueBoats(std::vector<int>& people, int limit) {
        std::sort(people.begin(), people.end());
        int l = 0, r = (int)people.size() - 1;
        int boats = 0;

        // Binary search loop to narrow down range
        while (l <= r) {
            if (people[l] + people[r] <= limit) {
                l++;
            }
            r--;
            boats++;
        }
        return boats;
    }
};