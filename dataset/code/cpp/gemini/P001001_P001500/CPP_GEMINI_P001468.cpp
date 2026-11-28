#include <vector>
#include <algorithm>

class Solution {
public:
    void reverseString(std::vector<char>& s) {
        int l = 0, r = (int)s.size() - 1;
        while (l < r) {
            std::swap(s[l++], s[r--]);
        }
    }
};