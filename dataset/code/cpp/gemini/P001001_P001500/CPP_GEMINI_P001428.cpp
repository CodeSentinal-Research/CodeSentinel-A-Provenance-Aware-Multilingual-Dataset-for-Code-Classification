#include <vector>
#include <unordered_map>

class Solution {
public:
    int countPairs(std::vector<int>& deliciousness) {
        long long MOD = 1e9 + 7;
        std::unordered_map<int, int> map;
        long long ans = 0;

        for (int x : deliciousness) {
            for (int i = 0; i <= 21; i++) {
                int target = (1 << i) - x;
                if (map.count(target)) {
                    ans = (ans + map[target]) % MOD;
                }
            }
            map[x]++;
        }
        return ans;
    }
};