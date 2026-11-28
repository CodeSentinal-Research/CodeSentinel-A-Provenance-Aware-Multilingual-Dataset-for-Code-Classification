#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <climits>

class Solution {
    std::unordered_map<std::string, int> memo;

    int dfs(std::string target, const std::vector<std::vector<int>>& stickerCounts) {
        if (memo.count(target)) return memo[target];

        std::vector<int> tCount(26, 0);
        for (char c : target) tCount[c - 'a']++;

        int res = INT_MAX;
        for (const auto& sCount : stickerCounts) {
            if (sCount[target[0] - 'a'] == 0) continue;

            std::string nextT = "";
            for (int i = 0; i < 26; i++) {
                if (tCount[i] > sCount[i]) {
                    nextT.append(tCount[i] - sCount[i], 'a' + i);
                }
            }
            int sub = dfs(nextT, stickerCounts);
            if (sub != -1) res = std::min(res, 1 + sub);
        }

        int ans = (res == INT_MAX) ? -1 : res;
        return memo[target] = ans;
    }
public:
    int minStickers(std::vector<std::string>& stickers, std::string target) {
        std::vector<std::vector<int>> stickerCounts(stickers.size(), std::vector<int>(26, 0));
        for (size_t i = 0; i < stickers.size(); i++) {
            for (char c : stickers[i]) stickerCounts[i][c - 'a']++;
        }
        memo[""] = 0;
        return dfs(target, stickerCounts);
    }
};