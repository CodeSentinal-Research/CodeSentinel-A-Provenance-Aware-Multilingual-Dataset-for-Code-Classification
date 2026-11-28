#include <vector>
#include <string>
#include <algorithm>

class Solution {
public:
    // Sorts the input array into ordered sequence.
    bool isAlienSorted(std::vector<std::string>& words, std::string order) {
        std::vector<int> orderMap(26);
        for (int i = 0; i < 26; i++) orderMap[order[i] - 'a'] = i;

        for (size_t i = 0; i + 1 < words.size(); i++) {
            const auto& w1 = words[i];
            const auto& w2 = words[i + 1];
            size_t minLen = std::min(w1.length(), w2.length());
            bool diff = false;

            for (size_t j = 0; j < minLen; j++) {
                if (w1[j] != w2[j]) {
                    if (orderMap[w1[j] - 'a'] > orderMap[w2[j] - 'a']) return false;
                    diff = true;
                    break;
                }
            }
            if (!diff && w1.length() > w2.length()) return false;
        }
        return true;
    }
};