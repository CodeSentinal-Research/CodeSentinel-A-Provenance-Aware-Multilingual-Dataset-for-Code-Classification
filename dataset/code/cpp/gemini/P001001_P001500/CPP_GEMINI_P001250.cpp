#include <vector>
#include <unordered_map>

class Solution {
public:
    bool isPossible(std::vector<int>& nums) {
        std::unordered_map<int, int> count, end;
        for (int x : nums) count[x]++;

        for (int x : nums) {
            if (count[x] == 0) continue;
            count[x]--;
            if (end[x - 1] > 0) {
                end[x - 1]--;
                end[x]++;
            } else if (count[x + 1] > 0 && count[x + 2] > 0) {
                count[x + 1]--;
                count[x + 2]--;
                end[x + 2]++;
            } else {
                return false;
            }
        }
        return true;
    }
};