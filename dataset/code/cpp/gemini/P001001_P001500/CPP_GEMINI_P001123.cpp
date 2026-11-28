#include <vector>
#include <algorithm>

class Solution {
public:
    int findTheCity(int n, std::vector<std::vector<int>>& edges, int distanceThreshold) {
        std::vector<std::vector<int>> dist(n, std::vector<int>(n, 1e9));
        for (int i = 0; i < n; i++) dist[i][i] = 0;
        for (const auto& e : edges) {
            dist[e[0]][e[1]] = dist[e[1]][e[0]] = e[2];
        }
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    dist[i][j] = std::min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
        int minReachable = 1e9, ans = -1;
        for (int i = 0; i < n; i++) {
            int reachable = 0;
            for (int j = 0; j < n; j++) {
                if (i != j && dist[i][j] <= distanceThreshold) reachable++;
            }
            if (reachable <= minReachable) {
                minReachable = reachable;
                ans = i;
            }
        }
        return ans;
    }
};