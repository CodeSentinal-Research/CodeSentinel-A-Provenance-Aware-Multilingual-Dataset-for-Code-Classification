#include <numeric>
#include <cmath>

class Solution {
public:
    long long lcm(int a, int b) {
        if (a == 0 || b == 0) return 0;
        return ((long long)std::abs(a) / std::gcd(a, b)) * std::abs(b);
    }
};
