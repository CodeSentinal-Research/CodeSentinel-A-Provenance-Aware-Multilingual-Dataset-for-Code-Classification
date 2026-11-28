#include <vector>
#include <unordered_map>
#include <algorithm>
class Solution {
public:
    int mostFrequent(std::vector<int>& nums) {
        std::unordered_map<int,int> cnt;
        for (int x : nums) cnt[x]++;
        return std::max_element(cnt.begin(), cnt.end(),
            [](auto& a, auto& b){ return a.second < b.second; })->first;
    }
};
