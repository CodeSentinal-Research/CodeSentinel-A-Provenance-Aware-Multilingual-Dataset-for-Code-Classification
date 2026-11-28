#include <algorithm>

class Solution {
public:
    int maxOfThree(int a, int b, int c) {
        return std::max({a, b, c});
    }
};
