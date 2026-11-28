#include <vector>
#include <algorithm>
#include <climits>

class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        int sold = 0, held = -1e9, reset = 0;
        for (int p : prices) {
            int preSold = sold;
            sold = held + p;
            held = std::max(held, reset - p);
            reset = std::max(reset, preSold);
        }
        return std::max(sold, reset);
    }
};