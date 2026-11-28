#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> rotateMatrix(int N, int M, int K, std::vector<std::vector<int>>& Mat) {
        int k = K % M;
        for (int i = 0; i < N; i++) {
            std::vector<int> temp(M);
            for (int j = 0; j < M; j++) {
                temp[j] = Mat[i][(j + k) % M];
            }
            Mat[i] = temp;
        }
        return Mat;
    }
};