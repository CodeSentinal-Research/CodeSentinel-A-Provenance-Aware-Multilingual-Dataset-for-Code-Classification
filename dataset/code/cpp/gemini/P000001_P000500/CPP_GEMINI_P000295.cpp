#include <string>
#include <cctype>
#include <climits>

class Solution {
public:
    int myAtoi(std::string s) {
        size_t i = 0;
        while (i < s.size() && s[i] == ' ') i++;
        if (i >= s.size()) return 0;

        int sign = 1;
        if (s[i] == '+' || s[i] == '-') {
            if (s[i] == '-') sign = -1;
            i++;
        }

        long long res = 0;
        while (i < s.size() && std::isdigit(s[i])) {
            res = res * 10 + (s[i] - '0');
            if (sign * res > INT_MAX) return INT_MAX;
            if (sign * res < INT_MIN) return INT_MIN;
            i++;
        }
        return (int)(sign * res);
    }
};