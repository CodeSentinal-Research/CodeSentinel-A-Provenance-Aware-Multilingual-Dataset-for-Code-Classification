#include <vector>
#include <algorithm>
#include <climits>
class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        int minPrice = INT_MAX, maxProfit = 0;
        for (int p : prices) {
            minPrice = std::min(minPrice, p);
            maxProfit = std::max(maxProfit, p - minPrice);
        }
        return maxProfit;
    }
};
