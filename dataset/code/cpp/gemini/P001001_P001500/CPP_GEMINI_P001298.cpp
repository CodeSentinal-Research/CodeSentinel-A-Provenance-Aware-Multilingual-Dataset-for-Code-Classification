#include <vector>
#include <numeric>
#include <algorithm>

class Solution {
public:
    long long numberOfWeeks(std::vector<int>& milestones) {
        long long total = 0, maxVal = 0;
        for (int m : milestones) {
            total += m;
            maxVal = std::max(maxVal, (long long)m);
        }
        long long rest = total - maxVal;

        if (maxVal > rest + 1) {
            return 2 * rest + 1;
        }
        return total;
    }
};