#include <vector>
#include <numeric>
#include <algorithm>
class Solution {
public:
    int rowWithMax1s(std::vector<std::vector<int>>& matrix) {
        int maxRow = -1, maxCount = -1;
        for (int i = 0; i < (int)matrix.size(); i++) {
            int cnt = std::accumulate(matrix[i].begin(), matrix[i].end(), 0);
            if (cnt > maxCount) { maxCount = cnt; maxRow = i; }
        }
        return maxRow;
    }
};
