#include <vector>
#include <queue>

class Solution {
public:
    int minRefuelStops(int target, int startFuel, std::vector<std::vector<int>>& stations) {
        std::priority_queue<int> pq;
        int stops = 0, curFuel = startFuel, i = 0, n = stations.size();
        while (curFuel < target) {
            while (i < n && stations[i][0] <= curFuel) {
                pq.push(stations[i][1]);
                i++;
            }
            if (pq.empty()) return -1;
            curFuel += pq.top();
            pq.pop();
            stops++;
        }
        return stops;
    }
};