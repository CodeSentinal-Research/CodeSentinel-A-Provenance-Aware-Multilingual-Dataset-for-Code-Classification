#include <vector>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    int longestWPI(std::vector<int>& hours) {
        int score = 0, ans = 0;
        std::unordered_map<int, int> seen;

        for (size_t i = 0; i < hours.size(); i++) {
            score += hours[i] > 8 ? 1 : -1;
            if (score > 0) {
                ans = i + 1;
            } else {
                if (!seen.count(score)) seen[score] = i;
                if (seen.count(score - 1)) {
                    ans = std::max(ans, (int)i - seen[score - 1]);
                }
            }
        }
        return ans;
    }
};