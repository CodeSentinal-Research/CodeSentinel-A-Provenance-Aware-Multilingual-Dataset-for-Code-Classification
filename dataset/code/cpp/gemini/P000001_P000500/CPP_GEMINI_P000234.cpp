#include <vector>

class Solution {
public:
    void booleanMatrix(std::vector<std::vector<int>>& matrix) {
        int R = matrix.size(), C = matrix[0].size();
        std::vector<int> rowFlag(R, 0), colFlag(C, 0);

        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (matrix[i][j] == 1) {
                    rowFlag[i] = 1;
                    colFlag[j] = 1;
                }
            }
        }

        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (rowFlag[i] == 1 || colFlag[j] == 1) {
                    matrix[i][j] = 1;
                }
            }
        }
    }
};