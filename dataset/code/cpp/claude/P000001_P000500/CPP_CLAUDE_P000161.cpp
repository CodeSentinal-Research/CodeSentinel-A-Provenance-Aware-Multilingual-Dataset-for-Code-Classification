#include <vector>
#include <unordered_map>
#include <set>
class Solution {
public:
    std::vector<std::pair<int,int>> findAllPairs(std::vector<int>& nums, int target) {
        std::unordered_map<int,int> cnt;
        for (int x : nums) cnt[x]++;
        std::vector<std::pair<int,int>> res;
        std::set<std::pair<int,int>> seen;
        for (int x : nums) {
            int y = target - x;
            if (cnt.count(y)) {
                auto key = std::make_pair(std::min(x,y), std::max(x,y));
                if (!seen.count(key)) {
                    if (x != y || cnt[x] >= 2) res.push_back(key);
                    seen.insert(key);
                }
            }
        }
        return res;
    }
};
