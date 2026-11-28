#include <vector>

class Solution {
public:
    int sumOfBoundaryElements(std::vector<std::vector<int>>& matrix) {
        int n = matrix.size();
        int sum = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 || j == 0 || i == n - 1 || j == n - 1) {
                    sum += matrix[i][j];
                }
            }
        }
        return sum;
    }
};