#include <vector>
#include <algorithm>
#include <unordered_map>
class Solution {
public:
    std::vector<int> frequencySort(std::vector<int>& nums) {
        std::unordered_map<int,int> cnt;
        for (int x : nums) cnt[x]++;
        std::vector<int> res = nums;
        std::sort(res.begin(), res.end(), [&](int a, int b){
            return cnt[a] != cnt[b] ? cnt[a] > cnt[b] : a < b;
        });
        return res;
    }
};
