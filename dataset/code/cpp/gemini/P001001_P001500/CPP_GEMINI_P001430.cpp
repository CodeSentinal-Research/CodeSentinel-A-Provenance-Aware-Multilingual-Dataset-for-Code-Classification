#include <vector>

class Solution {
public:
    std::vector<int> findThePrefixCommonArray(std::vector<int>& A, std::vector<int>& B) {
        int n = A.size();
        std::vector<int> res(n, 0);
        std::vector<int> count(n + 1, 0);
        int common = 0;

        for (int i = 0; i < n; i++) {
            if (++count[A[i]] == 2) common++;
            if (++count[B[i]] == 2) common++;
            res[i] = common;
        }
        return res;
    }
};