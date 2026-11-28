#include <vector>
#include <queue>
#include <algorithm>

class Solution {
public:
    int maxPerformance(int n, std::vector<int>& speed, std::vector<int>& efficiency, int k) {
        std::vector<std::pair<int, int>> engineers(n);
        for (int i = 0; i < n; i++) {
            engineers[i] = {efficiency[i], speed[i]};
        }
        std::sort(engineers.rbegin(), engineers.rend());
        std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
        long long speedSum = 0, best = 0;
        for (const auto& [eff, spd] : engineers) {
            pq.push(spd);
            speedSum += spd;
            if ((int)pq.size() > k) {
                speedSum -= pq.top();
                pq.pop();
            }
            best = std::max(best, speedSum * eff);
        }
        return best % 1000000007LL;
    }
};