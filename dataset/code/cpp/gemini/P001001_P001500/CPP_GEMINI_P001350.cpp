#include <string>
#include <vector>

class Solution {
    std::vector<std::string> res;
    void backtrack(int n, std::string cur) {
        if ((int)cur.length() == n) {
            res.push_back(cur);
            return;
        }
        for (char c : {'a', 'b', 'c'}) {
            if (cur.empty() || cur.back() != c) {
                backtrack(n, cur + c);
            }
        }
    }
public:
    std::string getHappyString(int n, int k) {
        backtrack(n, "");
        return k <= (int)res.size() ? res[k - 1] : "";
    }
};