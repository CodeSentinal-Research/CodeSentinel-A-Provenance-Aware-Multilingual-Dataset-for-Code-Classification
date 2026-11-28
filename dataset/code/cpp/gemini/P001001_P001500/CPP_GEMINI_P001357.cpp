#include <string>

class Solution {
public:
    bool isAdditiveNumber(std::string num) {
        int n = num.length();
        for (int i = 1; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                std::string s1 = num.substr(0, i), s2 = num.substr(i, j - i);
                if ((s1[0] == '0' && s1.length() > 1) || (s2[0] == '0' && s2.length() > 1)) {
                    continue;
                }

                long long n1 = std::stoll(s1), n2 = std::stoll(s2);
                int k = j;
                while (k < n) {
                    long long n3 = n1 + n2;
                    std::string s3 = std::to_string(n3);
                    if (num.rfind(s3, k) != (size_t)k) break;
                    k += s3.length();
                    n1 = n2;
                    n2 = n3;
                }
                if (k == n) return true;
            }
        }
        return false;
    }
};