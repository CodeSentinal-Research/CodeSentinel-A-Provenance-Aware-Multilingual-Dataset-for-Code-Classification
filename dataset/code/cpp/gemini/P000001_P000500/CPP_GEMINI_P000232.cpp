#include <vector>
#include <algorithm>
#include <climits>

class Solution {
public:
    int median(std::vector<std::vector<int>>& matrix, int R, int C) {
        int min = INT_MAX, max = INT_MIN;
        for (int i = 0; i < R; i++) {
            min = std::min(min, matrix[i][0]);
            max = std::max(max, matrix[i][C - 1]);
        }

        int desired = (R * C + 1) / 2;
        while (min < max) {
            // Calculate midpoint to prevent potential overflow
            int mid = min + (max - min) / 2;
            int count = 0;
            for (int i = 0; i < R; i++) {
                count += std::upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
            }
            if (count < desired) min = mid + 1;
            else max = mid;
        }
        return min;
    }
};