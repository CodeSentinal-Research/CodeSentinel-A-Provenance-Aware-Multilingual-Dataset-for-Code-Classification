#include <vector>
#include <unordered_map>

class Solution {
public:
    int numEquivDominoPairs(std::vector<std::vector<int>>& dominoes) {
        std::vector<int> count(100, 0);
        int ans = 0;

        for (const auto& d : dominoes) {
            int val = d[0] < d[1] ? d[0] * 10 + d[1] : d[1] * 10 + d[0];
            ans += count[val]++;
        }
        return ans;
    }
};