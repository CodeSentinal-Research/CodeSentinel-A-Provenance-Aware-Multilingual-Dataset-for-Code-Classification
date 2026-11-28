#include <vector>
#include <climits>
class Solution {
public:
    int secondSmallest(std::vector<int>& nums) {
        int first = INT_MAX, second = INT_MAX;
        for (int x : nums) {
            if (x < first) { second = first; first = x; }
            else if (x < second && x != first) second = x;
        }
        return second == INT_MAX ? -1 : second;
    }
};
