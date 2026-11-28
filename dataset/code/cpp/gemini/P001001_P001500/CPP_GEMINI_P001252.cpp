#include <vector>
#include <algorithm>
#include <climits>

class Solution {
public:
    int findLongestChain(std::vector<std::vector<int>>& pairs) {
        std::sort(pairs.begin(), pairs.end(), [](const auto& a, const auto& b) {
            return a[1] < b[1];
        });
        int cur = INT_MIN, ans = 0;
        for (const auto& p : pairs) {
            if (cur < p[0]) {
                cur = p[1];
                ans++;
            }
        }
        return ans;
    }
};