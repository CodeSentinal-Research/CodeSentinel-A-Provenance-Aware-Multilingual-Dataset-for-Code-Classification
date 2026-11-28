#include <vector>

class Solution {
public:
    std::vector<int> printNos(int n) {
        std::vector<int> res(n);
        for (int i = 0; i < n; i++) res[i] = i + 1;
        return res;
    }
};
