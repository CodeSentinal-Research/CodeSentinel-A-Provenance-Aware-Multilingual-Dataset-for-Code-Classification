#include <vector>
#include <algorithm>
class Solution {
public:
    int countTriplets(std::vector<int>& nums, int target) {
        std::sort(nums.begin(), nums.end());
        int n = nums.size(), count = 0;
        for (int i = 0; i < n-2; i++) {
            int l = i+1, r = n-1;
            while (l < r) {
                int s = nums[i]+nums[l]+nums[r];
                if (s == target) {
                    if (nums[l]==nums[r]) { int m=r-l+1; count+=m*(m-1)/2; break; }
                    int lc=1,rc=1;
                    while (l+lc<r && nums[l+lc]==nums[l]) lc++;
                    while (r-rc>l && nums[r-rc]==nums[r]) rc++;
                    count+=lc*rc; l+=lc; r-=rc;
                } else if (s < target) l++;
                else r--;
            }
        }
        return count;
    }
};
