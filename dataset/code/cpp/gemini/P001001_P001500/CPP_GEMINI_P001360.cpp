#include <vector>
#include <string>
#include <algorithm>

class Solution {
    int backtrack(size_t idx, const std::vector<std::string>& words, std::vector<int>& count, const std::vector<int>& score) {
        if (idx == words.size()) return 0;
        int maxS = backtrack(idx + 1, words, count, score);

        const std::string& w = words[idx];
        std::vector<int> wCount(26, 0);
        int wScore = 0;
        bool canForm = true;

        for (char c : w) {
            int code = c - 'a';
            wCount[code]++;
            wScore += score[code];
            if (wCount[code] > count[code]) canForm = false;
        }

        if (canForm) {
            for (int i = 0; i < 26; i++) count[i] -= wCount[i];
            maxS = std::max(maxS, wScore + backtrack(idx + 1, words, count, score));
            for (int i = 0; i < 26; i++) count[i] += wCount[i];
        }
        return maxS;
    }
public:
    int maxScoreWords(std::vector<std::string>& words, std::vector<char>& letters, std::vector<int>& score) {
        std::vector<int> count(26, 0);
        for (char c : letters) count[c - 'a']++;
        return backtrack(0, words, count, score);
    }
};