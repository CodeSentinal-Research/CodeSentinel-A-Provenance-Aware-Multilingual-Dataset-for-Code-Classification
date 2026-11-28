#include <vector>
#include <algorithm>

class Solution {
    int helper(std::vector<int>& nums, int L, int M) {
        int sumL = 0, sumM = 0;
        for (int i = 0; i < L; i++) sumL += nums[i];
        for (int i = L; i < L + M; i++) sumM += nums[i];

        int maxL = sumL;
        int ans = sumL + sumM;

        for (size_t i = L + M; i < nums.size(); i++) {
            sumL += nums[i - M] - nums[i - L - M];
            maxL = std::max(maxL, sumL);
            sumM += nums[i] - nums[i - M];
            ans = std::max(ans, maxL + sumM);
        }
        return ans;
    }
public:
    int maxSumTwoNoOverlap(std::vector<int>& nums, int firstLen, int secondLen) {
        return std::max(helper(nums, firstLen, secondLen), helper(nums, secondLen, firstLen));
    }
};