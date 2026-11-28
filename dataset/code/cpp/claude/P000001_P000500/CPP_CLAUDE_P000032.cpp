#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<int> getFactors(int n) {
        if (n <= 0) return {};
        std::vector<int> factors;
        for (long long i = 1; i * i <= n; i++) {
            if (n % i == 0) {
                factors.push_back(i);
                if (i * i != n) factors.push_back(n / i);
            }
        }
        std::sort(factors.begin(), factors.end());
        return factors;
    }
};
