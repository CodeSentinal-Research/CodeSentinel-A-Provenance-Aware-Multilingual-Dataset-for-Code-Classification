#include <vector>

class Solution {
public:
    std::vector<int> printNosReverse(int n) {
        std::vector<int> res(n);
        for (int i = 0; i < n; i++) res[i] = n - i;
        return res;
    }
};
