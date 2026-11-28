#include <vector>
#include <utility>
class Solution {
public:
    std::pair<int,int> findMissingRepeating(std::vector<int>& nums) {
        int n = nums.size();
        std::vector<int> cnt(n + 1, 0);
        int rep = -1, miss = -1;
        for (int x : nums) { cnt[x]++; if (cnt[x] == 2) rep = x; }
        for (int i = 1; i <= n; i++) if (cnt[i] == 0) { miss = i; break; }
        return {rep, miss};
    }
};
