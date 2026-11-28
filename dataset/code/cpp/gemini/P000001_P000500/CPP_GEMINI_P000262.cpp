#include <string>
#include <unordered_map>

class Solution {
public:
    char nonrepeatingCharacter(std::string s) {
        std::unordered_map<char, int> freq;
        for (char c : s) freq[c]++;
        for (char c : s) {
            if (freq[c] == 1) return c;
        }
        return '$';
    }
};