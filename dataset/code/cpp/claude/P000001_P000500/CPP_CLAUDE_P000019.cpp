#include <vector>

class Solution {
public:
    std::vector<int> getMultiplicationTable(int n, int limit = 10) {
        std::vector<int> res(limit);
        for (int i = 1; i <= limit; i++) {
            res[i - 1] = n * i;
        }
        return res;
    }
};
