#include <vector>

class Solution {
public:
    bool isSameBSTSeq(std::vector<int>& a, std::vector<int>& b) {
        if (a.size() != b.size()) return false;
        if (a.empty()) return true;
        if (a[0] != b[0]) return false;

        std::vector<int> leftA, rightA, leftB, rightB;
        for (size_t i = 1; i < a.size(); i++) {
            if (a[i] < a[0]) leftA.push_back(a[i]);
            else rightA.push_back(a[i]);

            if (b[i] < b[0]) leftB.push_back(b[i]);
            else rightB.push_back(b[i]);
        }

        return isSameBSTSeq(leftA, leftB) && isSameBSTSeq(rightA, rightB);
    }
};