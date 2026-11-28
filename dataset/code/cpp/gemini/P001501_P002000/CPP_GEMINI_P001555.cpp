#include <string>
#include <unordered_set>
#include <algorithm>

class Solution {
public:
    int maxVowels(std::string s, int k) {
        std::unordered_set<char> vowels{'a', 'e', 'i', 'o', 'u'};
        int curVowels = 0;
        for (int i = 0; i < k; i++) if (vowels.count(s[i])) curVowels++;
        int maxVowels = curVowels;

        for (size_t i = k; i < s.length(); i++) {
            if (vowels.count(s[i])) curVowels++;
            if (vowels.count(s[i - k])) curVowels--;
            maxVowels = std::max(maxVowels, curVowels);
        }
        return maxVowels;
    }
};