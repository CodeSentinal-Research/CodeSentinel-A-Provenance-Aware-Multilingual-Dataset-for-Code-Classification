#include <vector>
#include <algorithm>
class Solution {
public:
    int getMaxLen(std::vector<int>& nums) {
        int pos = 0, neg = 0, best = 0;
        for (int x : nums) {
            if (x == 0) { pos = neg = 0; }
            else if (x > 0) { pos++; neg = neg > 0 ? neg+1 : 0; }
            else { int np = neg>0 ? neg+1 : 0; neg = pos+1; pos = np; }
            best = std::max(best, pos);
        }
        return best;
    }
};
