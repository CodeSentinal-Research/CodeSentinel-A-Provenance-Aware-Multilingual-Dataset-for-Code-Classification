#include <vector>
#include <queue>
#include <algorithm>

class Solution {
public:
    int maxEvents(std::vector<std::vector<int>>& events) {
        std::sort(events.begin(), events.end());
        std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
        int day = 0, count = 0, i = 0, n = events.size();

        while (i < n || !pq.empty()) {
            if (pq.empty()) {
                day = events[i][0];
            }
            while (i < n && events[i][0] <= day) {
                pq.push(events[i++][1]);
            }
            pq.pop();
            count++;
            day++;
            while (!pq.empty() && pq.top() < day) {
                pq.pop();
            }
        }
        return count;
    }
};