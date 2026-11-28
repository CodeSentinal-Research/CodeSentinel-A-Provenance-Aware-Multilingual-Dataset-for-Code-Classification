#include <vector>
#include <unordered_map>

class Solution {
public:
    int numberOfBoomerangs(std::vector<std::vector<int>>& points) {
        int ans = 0;
        for (const auto& p1 : points) {
            std::unordered_map<int, int> map;
            for (const auto& p2 : points) {
                int dx = p1[0] - p2[0];
                int dy = p1[1] - p2[1];
                map[dx * dx + dy * dy]++;
            }
            for (const auto& [_, count] : map) {
                ans += count * (count - 1);
            }
        }
        return ans;
    }
};