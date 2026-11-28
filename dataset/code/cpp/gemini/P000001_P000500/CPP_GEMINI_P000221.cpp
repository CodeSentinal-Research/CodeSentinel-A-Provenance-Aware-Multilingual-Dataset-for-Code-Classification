#include <vector>
#include <algorithm>
#include <climits>

class Solution {
public:
    int findLongestChain(std::vector<std::vector<int>>& pairs) {
        std::sort(pairs.begin(), pairs.end(), [](const auto& a, const auto& b) {
            return a[1] < b[1];
        });
        int curEnd = INT_MIN;
        int chain = 0;

        for (auto& p : pairs) {
            if (p[0] > curEnd) {
                chain++;
                curEnd = p[1];
            }
        }
        return chain;
    }
};