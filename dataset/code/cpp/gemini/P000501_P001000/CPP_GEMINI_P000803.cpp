#include <vector>
#include <unordered_map>

class Solution {
public:
    int numSubmatrixSumTarget(std::vector<std::vector<int>>& matrix, int target) {
        int r = matrix.size(), c = matrix[0].size();
        for (int i = 0; i < r; i++) {
            for (int j = 1; j < c; j++) {
                matrix[i][j] += matrix[i][j - 1];
            }
        }

        int count = 0;
        for (int c1 = 0; c1 < c; c1++) {
            for (int c2 = c1; c2 < c; c2++) {
                std::unordered_map<int, int> mp;
                mp[0] = 1;
                int curSum = 0;
                for (int row = 0; row < r; row++) {
                    curSum += matrix[row][c2] - (c1 > 0 ? matrix[row][c1 - 1] : 0);
                    if (mp.find(curSum - target) != mp.end()) {
                        count += mp[curSum - target];
                    }
                    mp[curSum]++;
                }
            }
        }
        return count;
    }
};