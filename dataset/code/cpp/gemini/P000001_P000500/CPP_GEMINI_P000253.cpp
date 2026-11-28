#include <string>
#include <unordered_set>

class Solution {
public:
    int countVowels(std::string s) {
        std::unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        int count = 0;
        for (char c : s) {
            if (vowels.count(c)) count++;
        }
        return count;
    }
};