#include <vector>

class Solution {
public:
    std::vector<int> commonElements(std::vector<int>& A, std::vector<int>& B, std::vector<int>& C) {
        int i = 0, j = 0, k = 0;
        std::vector<int> res;

        while (i < (int)A.size() && j < (int)B.size() && k < (int)C.size()) {
            if (A[i] == B[j] && B[j] == C[k]) {
                if (res.empty() || res.back() != A[i]) {
                    res.push_back(A[i]);
                }
                i++; j++; k++;
            } else if (A[i] < B[j]) {
                i++;
            } else if (B[j] < C[k]) {
                j++;
            } else {
                k++;
            }
        }
        return res;
    }
};