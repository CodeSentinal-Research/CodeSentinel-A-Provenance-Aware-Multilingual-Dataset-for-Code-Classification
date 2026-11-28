#include <string>
#include <vector>
#include <algorithm>

class Solution {
public:
    int numberOfSubstrings(std::string s) {
        std::vector<int> last(3, -1);
        int ans = 0;

        for (size_t i = 0; i < s.length(); i++) {
            last[s[i] - 'a'] = i;
            ans += 1 + std::min({last[0], last[1], last[2]});
        }
        return ans;
    }
};