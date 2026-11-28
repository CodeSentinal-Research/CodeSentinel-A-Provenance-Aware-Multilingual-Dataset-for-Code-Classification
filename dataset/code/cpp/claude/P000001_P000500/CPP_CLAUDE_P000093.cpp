#include <cmath>

class Solution {
public:
    double sumOfGP(double a, double r, int n) {
        if (r == 1.0) return a * n;
        return a * (1 - std::pow(r, n)) / (1 - r);
    }
};
