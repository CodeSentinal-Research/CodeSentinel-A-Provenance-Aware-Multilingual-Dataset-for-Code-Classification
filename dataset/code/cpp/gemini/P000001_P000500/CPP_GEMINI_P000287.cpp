#include <string>
#include <unordered_set>

class Solution {
public:
    std::string reverseVowels(std::string s) {
        std::unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        int i = 0, j = (int)s.size() - 1;
        while (i < j) {
            if (!vowels.count(s[i])) i++;
            else if (!vowels.count(s[j])) j--;
            else {
                std::swap(s[i], s[j]);
                i++; j--;
            }
        }
        return s;
    }
};