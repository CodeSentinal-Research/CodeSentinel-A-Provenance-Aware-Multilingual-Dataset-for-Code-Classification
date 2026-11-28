#include <stdexcept>

class Solution {
public:
    double divide(int a, int b) {
        if (b == 0) {
            throw std::invalid_argument("Division by zero");
        }
        return static_cast<double>(a) / b;
    }
};
