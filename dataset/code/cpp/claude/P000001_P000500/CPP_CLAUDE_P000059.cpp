#include <cmath>

class Solution {
public:
    long long productOfDigits(int n) {
        n = std::abs(n);
        if (n == 0) return 0;
        long long prod = 1;
        while (n > 0) {
            prod *= (n % 10);
            n /= 10;
        }
        return prod;
    }
};
