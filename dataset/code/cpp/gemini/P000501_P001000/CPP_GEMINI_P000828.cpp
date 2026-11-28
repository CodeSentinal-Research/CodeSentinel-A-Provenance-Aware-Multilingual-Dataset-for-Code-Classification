#include <vector>
#include <map>

class Solution {
public:
    std::vector<int> findRightInterval(std::vector<std::vector<int>>& intervals) {
        std::map<int, int> mp;
        for (int i = 0; i < (int)intervals.size(); i++) {
            mp[intervals[i][0]] = i;
        }
        std::vector<int> res(intervals.size());
        for (int i = 0; i < (int)intervals.size(); i++) {
            auto it = mp.lower_bound(intervals[i][1]);
            res[i] = (it == mp.end()) ? -1 : it->second;
        }
        return res;
    }
};