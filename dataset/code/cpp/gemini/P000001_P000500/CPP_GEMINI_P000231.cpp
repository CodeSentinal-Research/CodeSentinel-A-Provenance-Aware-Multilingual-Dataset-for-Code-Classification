#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> sortedMatrix(int N, std::vector<std::vector<int>>& Mat) {
        std::vector<int> flat;
        for (auto& row : Mat) {
            for (int x : row) flat.push_back(x);
        }
        std::sort(flat.begin(), flat.end());
        int idx = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) Mat[i][j] = flat[idx++];
        }
        return Mat;
    }
};