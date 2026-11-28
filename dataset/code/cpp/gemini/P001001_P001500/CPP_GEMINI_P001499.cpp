#include <string>
#include <algorithm>

class Solution {
public:
    std::string reversePrefix(std::string word, char ch) {
        size_t idx = word.find(ch);
        if (idx != std::string::npos) {
            std::reverse(word.begin(), word.begin() + idx + 1);
        }
        return word;
    }
};