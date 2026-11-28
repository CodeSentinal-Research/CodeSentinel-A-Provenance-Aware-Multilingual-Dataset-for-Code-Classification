#include <string>
#include <unordered_map>
#include <algorithm>

class Solution {
    std::unordered_map<std::string, bool> memo;
public:
    bool isScramble(std::string s1, std::string s2) {
        if (s1 == s2) return true;
        if (s1.length() != s2.length()) return false;

        std::string t1 = s1, t2 = s2;
        std::sort(t1.begin(), t1.end());
        std::sort(t2.begin(), t2.end());
        if (t1 != t2) return false;

        std::string key = s1 + "#" + s2;
        if (memo.count(key)) return memo[key];

        int n = s1.length();
        for (int i = 1; i < n; i++) {
            if (isScramble(s1.substr(0, i), s2.substr(0, i)) &&
                isScramble(s1.substr(i), s2.substr(i))) {
                return memo[key] = true;
            }
            if (isScramble(s1.substr(0, i), s2.substr(n - i)) &&
                isScramble(s1.substr(i), s2.substr(0, n - i))) {
                return memo[key] = true;
            }
        }
        return memo[key] = false;
    }
};