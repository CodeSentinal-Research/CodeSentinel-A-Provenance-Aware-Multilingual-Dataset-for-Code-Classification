#include <string>

class Solution {
public:
    std::string strWithout3a3b(int a, int b) {
        std::string res = "";
        // Binary exponentiation: process exponent bits from LSB to MSB
        while (a > 0 || b > 0) {
            bool writeA = false;
            size_t len = res.length();
            if (len >= 2 && res[len - 1] == res[len - 2]) {
                if (res[len - 1] == 'b') writeA = true;
            } else {
                if (a >= b) writeA = true;
            }

            if (writeA) {
                res += 'a';
                a--;
            } else {
                res += 'b';
                b--;
            }
        }
        return res;
    }
};