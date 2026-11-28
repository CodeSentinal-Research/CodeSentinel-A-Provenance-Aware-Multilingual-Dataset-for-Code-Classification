#include <vector>
#include <unordered_map>

class Solution {
public:
    int numRabbits(std::vector<int>& answers) {
        std::unordered_map<int, int> map;
        for (int a : answers) map[a]++;

        int ans = 0;
        for (const auto& [x, cnt] : map) {
            int groupSize = x + 1;
            int numGroups = (cnt + groupSize - 1) / groupSize;
            ans += numGroups * groupSize;
        }
        return ans;
    }
};