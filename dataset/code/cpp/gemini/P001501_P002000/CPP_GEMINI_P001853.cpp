#include <vector>

class Solution {
public:
    bool hasOnlyOneChild(std::vector<int>& preorder) {
        int n = preorder.size();
        for (int i = 0; i < n - 1; i++) {
            int nextDiff = preorder[i] - preorder[i + 1];
            int lastDiff = preorder[i] - preorder[n - 1];
            if ((long long)nextDiff * lastDiff < 0) return false;
        }
        return true;
    }
};