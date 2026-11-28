#include <vector>
#include <string>
#include <algorithm>

class Solution {
public:
    std::string rankTeams(std::vector<std::string>& votes) {
        int n = votes[0].length();
        std::vector<std::vector<int>> rank(26, std::vector<int>(n + 1, 0));

        for (int i = 0; i < 26; i++) rank[i][n] = i;

        for (const auto& v : votes) {
            for (int i = 0; i < n; i++) {
                rank[v[i] - 'A'][i]--;
            }
        }

        std::string res = votes[0];
        std::sort(res.begin(), res.end(), [&](char a, char b) {
            return rank[a - 'A'] < rank[b - 'A'];
        });
        return res;
    }
};