#include <numeric>
#include <cmath>

class Solution {
public:
    long long lcmOfThree(int a, int b, int c) {
        long long l1 = std::lcm((long long)a, (long long)b);
        return std::lcm(l1, (long long)c);
    }
};
