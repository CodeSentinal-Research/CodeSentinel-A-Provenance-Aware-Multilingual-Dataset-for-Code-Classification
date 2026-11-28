#include <vector>
#include <string>
#include <unordered_map>

class Solution {
public:
    std::vector<int> findSubstring(std::string s, std::vector<std::string>& words) {
        std::vector<int> res;
        if (s.empty() || words.empty()) return res;

        int wordLen = words[0].length();
        int numWords = words.size();
        std::unordered_map<std::string, int> wordCount;
        for (const auto& w : words) wordCount[w]++;

        for (int i = 0; i < wordLen; i++) {
            int left = i, count = 0;
            std::unordered_map<std::string, int> curCount;

            for (int j = i; j + wordLen <= (int)s.length(); j += wordLen) {
                std::string w = s.substr(j, wordLen);
                if (wordCount.count(w)) {
                    curCount[w]++;
                    count++;

                    while (curCount[w] > wordCount[w]) {
                        std::string leftW = s.substr(left, wordLen);
                        curCount[leftW]--;
                        count--;
                        left += wordLen;
                    }

                    if (count == numWords) res.push_back(left);
                } else {
                    curCount.clear();
                    count = 0;
                    left = j + wordLen;
                }
            }
        }
        return res;
    }
};