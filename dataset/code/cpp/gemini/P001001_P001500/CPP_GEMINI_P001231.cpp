#include <vector>
#include <algorithm>

class Solution {
public:
    int findContentChildren(std::vector<int>& g, std::vector<int>& s) {
        std::sort(g.begin(), g.end());
        std::sort(s.begin(), s.end());
        size_t childPtr = 0, cookiePtr = 0;

        while (childPtr < g.size() && cookiePtr < s.size()) {
            if (s[cookiePtr] >= g[childPtr]) {
                childPtr++;
            }
            cookiePtr++;
        }
        return childPtr;
    }
};