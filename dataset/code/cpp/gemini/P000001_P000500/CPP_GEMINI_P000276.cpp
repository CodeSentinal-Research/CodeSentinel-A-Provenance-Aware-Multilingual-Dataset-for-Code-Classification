#include <string>

class Solution {
public:
    std::string countAndSay(int n) {
        std::string s = "1";
        for (int step = 1; step < n; step++) {
            std::string nextS = "";
            int i = 0;
            while (i < (int)s.size()) {
                int count = 1;
                while (i + 1 < (int)s.size() && s[i] == s[i + 1]) {
                    i++;
                    count++;
                }
                nextS += std::to_string(count) + s[i];
                i++;
            }
            s = nextS;
        }
        return s;
    }
};