#include <utility>

class Solution {
public:
    std::pair<int, int> divideAndRemainder(int a, int b) {
        return {a / b, a % b};
    }
};
