#include <string>
#include <unordered_set>

class Solution {
public:
    int countVowelSubstrings(std::string word) {
        std::unordered_set<char> vowels{'a', 'e', 'i', 'o', 'u'};
        int ans = 0, n = word.length();

        for (int i = 0; i < n; i++) {
            std::unordered_set<char> seen;
            for (int j = i; j < n; j++) {
                if (!vowels.count(word[j])) break;
                seen.insert(word[j]);
                if (seen.size() == 5) ans++;
            }
        }
        return ans;
    }
};