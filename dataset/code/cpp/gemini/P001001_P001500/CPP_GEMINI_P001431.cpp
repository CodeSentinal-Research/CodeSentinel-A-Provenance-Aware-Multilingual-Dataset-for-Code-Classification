#include <vector>
#include <string>
#include <unordered_map>

class Solution {
public:
    int similarPairs(std::vector<std::string>& words) {
        std::unordered_map<int, int> map;
        int ans = 0;

        for (const auto& w : words) {
            int mask = 0;
            for (char c : w) mask |= (1 << (c - 'a'));
            ans += map[mask]++;
        }
        return ans;
    }
};