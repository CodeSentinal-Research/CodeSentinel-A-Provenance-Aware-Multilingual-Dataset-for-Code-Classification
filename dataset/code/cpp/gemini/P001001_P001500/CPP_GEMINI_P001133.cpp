#include <vector>
#include <algorithm>

class Solution {
public:
    int minCostClimbingStairs(std::vector<int>& cost) {
        int a = 0, b = 0;
        for (int x : cost) {
            int next = std::min(a, b) + x;
            a = b;
            b = next;
        }
        return std::min(a, b);
    }
};