#include <vector>
#include <numeric>

class Solution {
public:
    int canCompleteCircuit(std::vector<int>& gas, std::vector<int>& cost) {
        int totalGas = std::accumulate(gas.begin(), gas.end(), 0);
        int totalCost = std::accumulate(cost.begin(), cost.end(), 0);
        if (totalGas < totalCost) return -1;

        int total = 0, start = 0;
        for (size_t i = 0; i < gas.size(); i++) {
            total += gas[i] - cost[i];
            if (total < 0) {
                total = 0;
                start = (int)i + 1;
            }
        }
        return start;
    }
};