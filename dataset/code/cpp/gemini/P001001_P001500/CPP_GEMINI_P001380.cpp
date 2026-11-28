#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    std::string frequencySort(std::string s) {
        std::unordered_map<char, int> count;
        for (char c : s) count[c]++;

        std::vector<std::pair<char, int>> arr(count.begin(), count.end());
        std::sort(arr.begin(), arr.end(), [](const auto& a, const auto& b) {
            return a.second > b.second;
        });

        std::string res = "";
        for (const auto& [c, cnt] : arr) {
            res.append(cnt, c);
        }
        return res;
    }
};