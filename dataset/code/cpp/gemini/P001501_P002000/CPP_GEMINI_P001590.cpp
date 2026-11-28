#include <vector>
#include <deque>

class Solution {
public:
    int maximumRobots(std::vector<int>& chargeTimes, std::vector<int>& runningCosts, long long budget) {
        std::deque<int> dq;
        int l = 0;
        long long sumCost = 0;

        for (size_t r = 0; r < chargeTimes.size(); r++) {
            sumCost += runningCosts[r];
            while (!dq.empty() && chargeTimes[dq.back()] <= chargeTimes[r]) dq.pop_back();
            dq.push_back(r);

            while (l <= (int)r && chargeTimes[dq.front()] + (r - l + 1) * sumCost > budget) {
                if (dq.front() == l) dq.pop_front();
                sumCost -= runningCosts[l++];
            }
        }
        return chargeTimes.size() - l;
    }
};