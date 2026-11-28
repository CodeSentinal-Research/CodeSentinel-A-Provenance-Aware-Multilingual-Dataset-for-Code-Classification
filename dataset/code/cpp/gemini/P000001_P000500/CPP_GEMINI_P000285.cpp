#include <string>

class Solution {
public:
    bool isSubsequence(std::string A, std::string B) {
        size_t i = 0, j = 0;
        while (i < A.size() && j < B.size()) {
            if (A[i] == B[j]) i++;
            j++;
        }
        return i == A.size();
    }
};