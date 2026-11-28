#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<int> successfulPairs(std::vector<int>& spells, std::vector<int>& potions, long long success) {
        std::sort(potions.begin(), potions.end());
        int n = spells.size(), m = potions.size();
        std::vector<int> res(n);

        for (int i = 0; i < n; i++) {
            long long minPotion = (success + spells[i] - 1) / spells[i];
            auto it = std::lower_bound(potions.begin(), potions.end(), minPotion);
            res[i] = potions.end() - it;
        }
        return res;
    }
};