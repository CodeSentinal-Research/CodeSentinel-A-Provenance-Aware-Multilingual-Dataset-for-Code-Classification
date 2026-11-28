#include <vector>
#include <algorithm>

class Solution {
public:
    int maxEnvelopes(std::vector<std::vector<int>>& envelopes) {
        std::sort(envelopes.begin(), envelopes.end(), [](const auto& a, const auto& b) {
            return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0];
        });

        std::vector<int> tails;
        for (const auto& env : envelopes) {
            int h = env[1];
            auto it = std::lower_bound(tails.begin(), tails.end(), h);
            if (it == tails.end()) tails.push_back(h);
            else *it = h;
        }
        return tails.size();
    }
};