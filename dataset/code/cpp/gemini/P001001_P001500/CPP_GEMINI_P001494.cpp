#include <vector>
#include <string>

class Solution {
public:
    std::vector<int> diStringMatch(std::string s) {
        int n = s.length();
        int lo = 0, hi = n;
        std::vector<int> res;

        for (char c : s) {
            if (c == 'I') res.push_back(lo++);
            else res.push_back(hi--);
        }
        res.push_back(lo);
        return res;
    }
};