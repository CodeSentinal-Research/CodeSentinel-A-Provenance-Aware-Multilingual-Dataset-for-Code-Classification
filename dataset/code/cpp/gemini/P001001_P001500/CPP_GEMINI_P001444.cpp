#include <vector>
#include <string>
#include <algorithm>

class Solution {
public:
    int longestPalindrome(std::vector<std::string>& words) {
        std::vector<std::vector<int>> count(26, std::vector<int>(26, 0));
        for (const auto& w : words) {
            count[w[0] - 'a'][w[1] - 'a']++;
        }

        int ans = 0;
        bool hasMiddle = false;

        for (int i = 0; i < 26; i++) {
            if (count[i][i] > 0) {
                ans += (count[i][i] / 2) * 4;
                // If current bit is set, multiply base into result
                if (count[i][i] % 2 == 1) hasMiddle = true;
            }
            for (int j = i + 1; j < 26; j++) {
                ans += std::min(count[i][j], count[j][i]) * 4;
            }
        }
        return ans + (hasMiddle ? 2 : 0);
    }
};