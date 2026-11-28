#include <vector>
#include <unordered_map>

class Solution {
public:
    int numSubmatrixSumTarget(std::vector<std::vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int ans = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 1; j < n; j++) {
                matrix[i][j] += matrix[i][j - 1];
            }
        }

        for (int c1 = 0; c1 < n; c1++) {
            for (int c2 = c1; c2 < n; c2++) {
                std::unordered_map<int, int> count;
                count[0] = 1;
                int cur = 0;

                for (int r = 0; r < m; r++) {
                    cur += matrix[r][c2] - (c1 > 0 ? matrix[r][c1 - 1] : 0);
                    if (count.count(cur - target)) ans += count[cur - target];
                    count[cur]++;
                }
            }
        }
        return ans;
    }
};