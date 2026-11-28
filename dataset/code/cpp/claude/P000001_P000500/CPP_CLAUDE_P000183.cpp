#include <vector>
#include <unordered_map>
class Solution {
public:
    std::vector<int> countDistinct(std::vector<int>& nums, int k) {
        std::unordered_map<int,int> freq;
        std::vector<int> res;
        for (int i = 0; i < (int)nums.size(); i++) {
            freq[nums[i]]++;
            if (i >= k) {
                freq[nums[i-k]]--;
                if (freq[nums[i-k]] == 0) freq.erase(nums[i-k]);
            }
            if (i >= k-1) res.push_back(freq.size());
        }
        return res;
    }
};
