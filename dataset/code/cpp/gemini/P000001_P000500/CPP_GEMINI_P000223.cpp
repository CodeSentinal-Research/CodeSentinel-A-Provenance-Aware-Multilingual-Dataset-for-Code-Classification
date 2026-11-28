#include <vector>
#include <algorithm>
#include <climits>

class Solution {
public:
    int activitySelection(std::vector<int>& start, std::vector<int>& end, int n) {
        std::vector<std::pair<int, int>> act(n);
        for (int i = 0; i < n; i++) act[i] = {start[i], end[i]};
        std::sort(act.begin(), act.end(), [](const auto& a, const auto& b) {
            return a.second < b.second;
        });

        int count = 0, lastEnd = INT_MIN;
        for (auto& p : act) {
            if (p.first > lastEnd) {
                count++;
                lastEnd = p.second;
            }
        }
        return count;
    }
};