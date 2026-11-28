#include <string>
#include <cctype>
#include <unordered_set>

class Solution {
public:
    std::string removeConsonants(std::string s) {
        std::unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        std::string res = "";
        for (char c : s) {
            if (!std::isalpha(c) || vowels.count(c)) res += c;
        }
        return res;
    }
};