#include <cmath>

class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num < 0) return false;
        long long r = std::sqrt(num);
        return r * r == num;
    }
};
