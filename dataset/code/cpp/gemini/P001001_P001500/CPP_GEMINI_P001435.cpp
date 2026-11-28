#include <vector>
#include <string>
#include <unordered_map>

class Solution {
public:
    int countWords(std::vector<std::string>& words1, std::vector<std::string>& words2) {
        std::unordered_map<std::string, int> c1, c2;
        for (const auto& w : words1) c1[w]++;
        for (const auto& w : words2) c2[w]++;

        int ans = 0;
        for (const auto& [w, cnt] : c1) {
            if (cnt == 1 && c2[w] == 1) ans++;
        }
        return ans;
    }
};