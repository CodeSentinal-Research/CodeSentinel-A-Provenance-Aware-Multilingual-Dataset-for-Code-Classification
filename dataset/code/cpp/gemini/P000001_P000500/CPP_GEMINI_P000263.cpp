#include <string>
#include <unordered_map>

class Solution {
public:
    char lastNonRepeatingCharacter(std::string s) {
        std::unordered_map<char, int> freq;
        for (char c : s) freq[c]++;
        for (int i = (int)s.size() - 1; i >= 0; i--) {
            if (freq[s[i]] == 1) return s[i];
        }
        return '$';
    }
};