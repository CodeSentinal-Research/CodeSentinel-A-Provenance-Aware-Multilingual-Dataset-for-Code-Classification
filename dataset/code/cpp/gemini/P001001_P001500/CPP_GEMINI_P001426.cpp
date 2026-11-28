#include <vector>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    int findLucky(std::vector<int>& arr) {
        std::unordered_map<int, int> map;
        for (int x : arr) map[x]++;

        int maxLucky = -1;
        for (const auto& [k, v] : map) {
            if (k == v) {
                maxLucky = std::max(maxLucky, k);
            }
        }
        return maxLucky;
    }
};