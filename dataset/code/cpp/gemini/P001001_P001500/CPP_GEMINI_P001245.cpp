#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> reconstructQueue(std::vector<std::vector<int>>& people) {
        std::sort(people.begin(), people.end(), [](const auto& a, const auto& b) {
            return a[0] == b[0] ? a[1] < b[1] : a[0] > b[0];
        });
        std::vector<std::vector<int>> res;
        for (const auto& p : people) {
            res.insert(res.begin() + p[1], p);
        }
        return res;
    }
};