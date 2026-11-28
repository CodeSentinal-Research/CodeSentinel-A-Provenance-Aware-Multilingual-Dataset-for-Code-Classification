#include <vector>
#include <unordered_map>
class Solution {
public:
    int countPairsWithSum(std::vector<int>& nums, int target) {
        std::unordered_map<int,int> cnt;
        for (int x : nums) cnt[x]++;
        int count = 0;
        std::unordered_map<int,bool> visited;
        for (auto& [x, cx] : cnt) {
            int y = target - x;
            if (cnt.count(y) && !visited[y]) {
                count += (x == y) ? cx*(cx-1)/2 : cx*cnt[y];
                visited[x] = true;
            }
        }
        return count;
    }
};
