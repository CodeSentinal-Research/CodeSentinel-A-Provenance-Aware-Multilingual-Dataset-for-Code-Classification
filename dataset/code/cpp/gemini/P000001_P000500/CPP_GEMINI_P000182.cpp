#include <vector>
#include <unordered_map>

class Solution {
public:
    int mostFrequent(std::vector<int>& nums) {
        std::unordered_map<int, int> freq;
        int maxCnt = 0, best = nums[0];
        for (int x : nums) {
            int cnt = ++freq[x];
            if (cnt > maxCnt) {
                maxCnt = cnt;
                best = x;
            }
        }
        return best;
    }
};