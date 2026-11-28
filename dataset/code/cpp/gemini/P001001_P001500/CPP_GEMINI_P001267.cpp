#include <vector>
#include <queue>

class Solution {
public:
    int furthestBuilding(std::vector<int>& heights, int bricks, int ladders) {
        std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
        for (size_t i = 0; i < heights.size() - 1; i++) {
            int diff = heights[i + 1] - heights[i];
            if (diff > 0) {
                pq.push(diff);
                if ((int)pq.size() > ladders) {
                    bricks -= pq.top();
                    pq.pop();
                }
                if (bricks < 0) return (int)i;
            }
        }
        return (int)heights.size() - 1;
    }
};