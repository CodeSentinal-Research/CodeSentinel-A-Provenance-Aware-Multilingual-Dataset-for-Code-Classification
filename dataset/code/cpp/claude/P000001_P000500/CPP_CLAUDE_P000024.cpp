#include <cmath>

class Solution {
public:
    int sumOfDigits(int n) {
        n = std::abs(n);
        int total = 0;
        while (n > 0) {
            total += n % 10;
            n /= 10;
        }
        return total;
    }
};
