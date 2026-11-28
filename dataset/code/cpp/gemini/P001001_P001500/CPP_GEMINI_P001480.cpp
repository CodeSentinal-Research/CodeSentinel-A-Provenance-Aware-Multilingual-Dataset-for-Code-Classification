#include <vector>
#include <string>
#include <algorithm>

class Solution {
public:
    std::vector<int> partitionLabels(std::string s) {
        std::vector<int> last(26, 0);
        for (size_t i = 0; i < s.length(); i++) last[s[i] - 'a'] = i;

        std::vector<int> res;
        int start = 0, end = 0;

        for (size_t i = 0; i < s.length(); i++) {
            end = std::max(end, last[s[i] - 'a']);
            if ((int)i == end) {
                res.push_back(end - start + 1);
                start = i + 1;
            }
        }
        return res;
    }
};