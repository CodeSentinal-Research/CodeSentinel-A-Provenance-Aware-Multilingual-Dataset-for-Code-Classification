#include <string>
#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<int> partitionLabels(std::string s) {
        std::vector<int> last(26, 0);
        for (size_t i = 0; i < s.length(); i++) {
            last[s[i] - 'a'] = (int)i;
        }

        std::vector<int> res;
        int anchor = 0, j = 0;
        for (size_t i = 0; i < s.length(); i++) {
            j = std::max(j, last[s[i] - 'a']);
            if ((int)i == j) {
                res.push_back((int)i - anchor + 1);
                anchor = (int)i + 1;
            }
        }
        return res;
    }
};