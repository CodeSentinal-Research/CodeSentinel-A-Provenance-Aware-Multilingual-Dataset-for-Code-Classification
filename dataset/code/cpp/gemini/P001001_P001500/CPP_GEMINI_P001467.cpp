#include <string>
#include <unordered_set>

class Solution {
public:
    std::string reverseVowels(std::string s) {
        std::unordered_set<char> vowels{'a','e','i','o','u','A','E','I','O','U'};
        int l = 0, r = (int)s.length() - 1;

        while (l < r) {
            while (l < r && !vowels.count(s[l])) l++;
            while (l < r && !vowels.count(s[r])) r--;
            std::swap(s[l], s[r]);
            l++;
            r--;
        }
        return s;
    }
};