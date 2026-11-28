#include <vector>
#include <queue>
#include <algorithm>
#include <cfloat>

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
        double qSum = 0, ans = DBL_MAX;
        for (const auto& [ratio, q] : workers) {
            pq.push(q);
            qSum += q;
            if ((int)pq.size() > k) {
                qSum -= pq.top();
                pq.pop();
            }
            if ((int)pq.size() == k) {
                ans = std::min(ans, qSum * ratio);
            }
        }
        return ans;
    }
};