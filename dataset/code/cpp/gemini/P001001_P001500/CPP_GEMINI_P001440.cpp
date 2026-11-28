#include <vector>
#include <string>

class Solution {
    bool isSubseq(const std::string& s, const std::string& w) {
        size_t i = 0, j = 0;
        while (i < s.length() && j < w.length()) {
            if (s[i] == w[j]) j++;
            i++;
        }
        return j == w.length();
    }
public:
    std::string findLongestWord(std::string s, std::vector<std::string>& dictionary) {
        std::string best = "";
        for (const auto& w : dictionary) {
            if (isSubseq(s, w)) {
                if (w.length() > best.length() || (w.length() == best.length() && w < best)) {
                    best = w;
                }
            }
        }
        return best;
    }
};