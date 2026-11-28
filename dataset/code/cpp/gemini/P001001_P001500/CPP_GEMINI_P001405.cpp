#include <vector>
#include <unordered_map>

class Solution {
    int rev(int n) {
        int res = 0;
        while (n > 0) {
            res = res * 10 + n % 10;
            n /= 10;
        }
        return res;
    }
public:
    int countNicePairs(std::vector<int>& nums) {
        std::unordered_map<int, int> map;
        long long ans = 0, MOD = 1e9 + 7;

        for (int x : nums) {
            int diff = x - rev(x);
            ans = (ans + map[diff]) % MOD;
            map[diff]++;
        }
        return ans;
    }
};