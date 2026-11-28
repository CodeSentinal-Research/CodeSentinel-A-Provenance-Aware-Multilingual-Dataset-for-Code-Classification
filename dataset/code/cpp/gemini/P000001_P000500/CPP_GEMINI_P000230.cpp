#include <vector>
#include <unordered_set>
#include <algorithm>

class Solution {
public:
    std::vector<int> findCommonElements(std::vector<std::vector<int>>& mat) {
        if (mat.empty()) return {};
        std::unordered_set<int> common(mat[0].begin(), mat[0].end());

        for (size_t i = 1; i < mat.size(); i++) {
            std::unordered_set<int> rowSet(mat[i].begin(), mat[i].end());
            std::vector<int> toErase;
            for (int x : common) {
                if (!rowSet.count(x)) toErase.push_back(x);
            }
            for (int x : toErase) common.erase(x);
        }

        std::vector<int> res(common.begin(), common.end());
        std::sort(res.begin(), res.end());
        return res;
    }
};