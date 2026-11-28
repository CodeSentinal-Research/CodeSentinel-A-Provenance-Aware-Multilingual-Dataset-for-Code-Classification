#include <vector>
#include <algorithm>

class Solution {
public:
    int countLargestGroup(int n) {
        std::vector<int> groups(40, 0);
        int maxSize = 0;

        for (int i = 1; i <= n; i++) {
            int s = 0, temp = i;
            while (temp > 0) {
                s += temp % 10;
                temp /= 10;
            }
            groups[s]++;
            maxSize = std::max(maxSize, groups[s]);
        }

        return std::count(groups.begin(), groups.end(), maxSize);
    }
};