#include <vector>
#include <algorithm>

class Solution {
public:
    int findCheapestPrice(int n, std::vector<std::vector<int>>& flights, int src, int dst, int k) {
        std::vector<int> dist(n, 1e9);
        dist[src] = 0;
        for (int i = 0; i <= k; i++) {
            std::vector<int> tmp = dist;
            for (const auto& f : flights) {
                if (dist[f[0]] != 1e9 && dist[f[0]] + f[2] < tmp[f[1]]) {
                    tmp[f[1]] = dist[f[0]] + f[2];
                }
            }
            dist = tmp;
        }
        return dist[dst] == 1e9 ? -1 : dist[dst];
    }
};