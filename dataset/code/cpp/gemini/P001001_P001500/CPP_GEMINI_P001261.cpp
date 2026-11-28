#include <vector>
#include <queue>

class Solution {
public:
    int minRefuelStops(int target, int startFuel, std::vector<std::vector<int>>& stations) {
        std::priority_queue<int> pq;
        long long cur = startFuel;
        int stops = 0;
        size_t i = 0, n = stations.size();

        while (cur < target) {
            while (i < n && stations[i][0] <= cur) {
                pq.push(stations[i++][1]);
            }
            if (pq.empty()) return -1;
            cur += pq.top();
            pq.pop();
            stops++;
        }
        return stops;
    }
};