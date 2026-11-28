#include <vector>
#include <climits>
class Solution {
public:
    int secondLargest(std::vector<int>& nums) {
        int first = INT_MIN, second = INT_MIN;
        for (int x : nums) {
            if (x > first) { second = first; first = x; }
            else if (x > second && x != first) second = x;
        }
        return second == INT_MIN ? -1 : second;
    }
};
