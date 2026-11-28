#include <string>
#include <vector>

class Solution {
public:
    int maximumSwap(int num) {
        std::string digits = std::to_string(num);
        std::vector<int> last(10, -1);
        for (size_t i = 0; i < digits.length(); i++) {
            last[digits[i] - '0'] = i;
        }

        for (size_t i = 0; i < digits.length(); i++) {
            for (int d = 9; d > digits[i] - '0'; d--) {
                if (last[d] > (int)i) {
                    std::swap(digits[i], digits[last[d]]);
                    return std::stoi(digits);
                }
            }
        }
        return num;
    }
};