#include <vector>
#include <unordered_map>
class Solution {
public:
    int firstNonRepeating(std::vector<int>& nums) {
        std::unordered_map<int,int> cnt;
        for (int x : nums) cnt[x]++;
        for (int x : nums) if (cnt[x] == 1) return x;
        return -1;
    }
};
