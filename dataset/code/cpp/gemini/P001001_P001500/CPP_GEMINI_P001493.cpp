#include <vector>
#include <string>
#include <algorithm>

class Solution {
public:
    std::vector<int> shortestToChar(std::string s, char c) {
        int n = s.length();
        std::vector<int> res(n);
        int pos = -n;

        for (int i = 0; i < n; i++) {
            if (s[i] == c) pos = i;
            res[i] = i - pos;
        }

        pos = 2 * n;
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == c) pos = i;
            res[i] = std::min(res[i], pos - i);
        }
        return res;
    }
};