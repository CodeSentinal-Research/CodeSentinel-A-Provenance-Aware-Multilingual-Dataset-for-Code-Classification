#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

class Solution {
public:
    double mincostToHireWorkers(std::vector<int>& quality, std::vector<int>& wage, int k) {
        int n = quality.size();
        std::vector<std::pair<double, int>> workers(n);
        for (int i = 0; i < n; i++) {
            workers[i] = {(double)wage[i] / quality[i], quality[i]};
        }
        std::sort(workers.begin(), workers.end());

        std::priority_queue<int> pq;
        double qualSum = 0, minCost = 1e18;

        for (const auto& [ratio, q] : workers) {
            pq.push(q);
            qualSum += q;
            if ((int)pq.size() > k) {
                qualSum -= pq.top();
                pq.pop();
            }
            if ((int)pq.size() == k) {
                minCost = std::min(minCost, qualSum * ratio);
            }
        }
        return minCost;
    }
};