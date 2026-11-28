#include <cmath>

class Solution {
public:
    double volumeOfSphere(double radius) {
        return (4.0 / 3.0) * M_PI * std::pow(radius, 3);
    }
};
