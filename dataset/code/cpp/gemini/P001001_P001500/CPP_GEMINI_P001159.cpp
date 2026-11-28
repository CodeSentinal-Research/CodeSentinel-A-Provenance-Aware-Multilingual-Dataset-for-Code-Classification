#include <string>

class Solution {
public:
    int numDecodings(std::string s) {
        if (s.empty() || s[0] == '0') return 0;
        int a = 1, b = 1;
        for (size_t i = 1; i < s.length(); i++) {
            int c = 0;
            if (s[i] != '0') c += b;
            int two = (s[i - 1] - '0') * 10 + (s[i] - '0');
            if (two >= 10 && two <= 26) c += a;
            a = b;
            b = c;
        }
        return b;
    }
};