#include <vector>
#include <queue>
#include <tuple>
#include <cmath>
#include <climits>

class Solution {
public:
    int minimumEffortPath(std::vector<std::vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        std::vector<std::vector<int>> dist(m, std::vector<int>(n, INT_MAX));
        dist[0][0] = 0;
        std::priority_queue<std::tuple<int, int, int>, std::vector<std::tuple<int, int, int>>, std::greater<std::tuple<int, int, int>>> pq;
        pq.push({0, 0, 0});

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while (!pq.empty()) {
            auto [d, r, c] = pq.top();
            pq.pop();
            if (r == m - 1 && c == n - 1) return d;
            if (d > dist[r][c]) continue;
            for (int k = 0; k < 4; k++) {
                int nr = r + dr[k], nc = c + dc[k];
                if (nr >= 0 && nr < m && nc >= 0 && nc < n) {
                    int effort = std::max(d, std::abs(heights[nr][nc] - heights[r][c]));
                    if (effort < dist[nr][nc]) {
                        dist[nr][nc] = effort;
                        pq.push({effort, nr, nc});
                    }
                }
            }
        }
        return 0;
    }
};