#include <vector>
#include <algorithm>
#include <numeric>
class Solution {
public:
    long long smallestSumK(std::vector<int>& nums, int k) {
        long long win=std::accumulate(nums.begin(),nums.begin()+k,0LL);
        long long best=win;
        for(int i=k;i<(int)nums.size();i++) {
            win+=nums[i]-nums[i-k];
            best=std::min(best,win);
        }
        return best;
    }
};
