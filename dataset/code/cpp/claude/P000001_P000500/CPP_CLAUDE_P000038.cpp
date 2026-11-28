#include <cmath>

class Solution {
public:
    double compoundInterest(double principal, double rate, double time) {
        double amount = principal * std::pow(1.0 + rate / 100.0, time);
        return amount - principal;
    }
};
