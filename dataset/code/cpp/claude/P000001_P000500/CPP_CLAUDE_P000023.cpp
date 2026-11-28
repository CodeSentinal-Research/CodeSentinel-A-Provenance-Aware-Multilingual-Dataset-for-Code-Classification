#include <vector>

class Solution {
public:
    std::vector<int> fibonacciSeries(int n) {
        if (n <= 0) return {};
        if (n == 1) return {0};
        std::vector<int> res(n);
        res[0] = 0;
        res[1] = 1;
        for (int i = 2; i < n; i++) {
            res[i] = res[i - 1] + res[i - 2];
        }
        return res;
    }
};
