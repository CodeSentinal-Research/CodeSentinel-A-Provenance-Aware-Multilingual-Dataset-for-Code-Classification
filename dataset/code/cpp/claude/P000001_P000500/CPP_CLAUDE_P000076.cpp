#include <cmath>
#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<double> findRoots(double a, double b, double c) {
        double d = b * b - 4 * a * c;
        if (d > 0) {
            double r1 = (-b + std::sqrt(d)) / (2 * a);
            double r2 = (-b - std::sqrt(d)) / (2 * a);
            return {std::max(r1, r2), std::min(r1, r2)};
        } else if (d == 0) {
            double r = -b / (2 * a);
            return {r, r};
        }
        return {};
    }
};
