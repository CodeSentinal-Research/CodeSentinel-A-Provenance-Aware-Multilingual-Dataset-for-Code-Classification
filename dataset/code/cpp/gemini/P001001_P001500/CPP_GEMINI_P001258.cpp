#include <string>
#include <vector>

class Solution {
public:
    std::string removeDuplicateLetters(std::string s) {
        std::vector<int> last(26, 0);
        for (size_t i = 0; i < s.length(); i++) last[s[i] - 'a'] = (int)i;

        std::vector<bool> seen(26, false);
        std::string stack = "";

        for (size_t i = 0; i < s.length(); i++) {
            char c = s[i];
            if (!seen[c - 'a']) {
                while (!stack.empty() && stack.back() > c && (int)i < last[stack.back() - 'a']) {
                    seen[stack.back() - 'a'] = false;
                    stack.pop_back();
                }
                seen[c - 'a'] = true;
                stack.push_back(c);
            }
        }
        return stack;
    }
};