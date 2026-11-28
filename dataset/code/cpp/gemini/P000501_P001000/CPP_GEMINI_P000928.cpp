#include <string>
#include <algorithm>

class Solution {
public:
    std::string addBinary(std::string a, std::string b) {
        std::string res = "";
        int i = a.length() - 1, j = b.length() - 1, carry = 0;
        while (i >= 0 || j >= 0 || carry) {
            int total = carry;
            if (i >= 0) total += (a[i--] - '0');
            if (j >= 0) total += (b[j--] - '0');
            res += std::to_string(total % 2);
            carry = total / 2;
        }
        std::reverse(res.begin(), res.end());
        return res;
    }
};