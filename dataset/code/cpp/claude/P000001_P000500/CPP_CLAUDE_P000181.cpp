#include <vector>
#include <algorithm>
class Solution {
    int solve(std::vector<int>& pre, int n, int L, int M) {
        int best=0, res=0;
        for (int i=L+M-1;i<n;i++) {
            best=std::max(best, pre[i-M+1]-pre[i-M+1-L]);
            res=std::max(res, best+pre[i+1]-pre[i+1-M]);
        }
        return res;
    }
public:
    int maxSumTwoNoOverlap(std::vector<int>& nums, int firstLen, int secondLen) {
        int n=nums.size();
        std::vector<int> pre(n+1,0);
        for (int i=0;i<n;i++) pre[i+1]=pre[i]+nums[i];
        return std::max(solve(pre,n,firstLen,secondLen), solve(pre,n,secondLen,firstLen));
    }
};
