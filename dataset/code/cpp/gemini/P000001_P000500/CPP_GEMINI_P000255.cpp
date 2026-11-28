#include <string>
#include <unordered_set>

class Solution {
public:
    std::string removeVowels(std::string s) {
        std::unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        std::string res = "";
        for (char c : s) {
            if (!vowels.count(c)) res += c;
        }
        return res;
    }
};