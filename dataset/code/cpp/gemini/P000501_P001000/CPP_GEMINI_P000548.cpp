#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
int main() {
    int r;
    if (std::cin >> r) {
        std::vector<std::vector<int>> routes(r);
        std::unordered_map<int, std::vector<int>> stop_to_routes;
        for (int i = 0; i < r; i++) {
            int k; std::cin >> k;
            routes[i].resize(k);
            for (int j = 0; j < k; j++) {
                std::cin >> routes[i][j];
                stop_to_routes[routes[i][j]].push_back(i);
            }
        }
        int source, target;
        std::cin >> source >> target;
        if (source == target) { std::cout << 0 << std::endl; return 0; }
        std::queue<std::pair<int, int>> q;
        std::unordered_set<int> vis_stops = {source};
        std::vector<bool> vis_routes(r, false);
        q.push({source, 0});
        int ans = -1;
        while (!q.empty()) {
            auto [stop, buses] = q.front(); q.pop();
            for (int bus : stop_to_routes[stop]) {
                if (!vis_routes[bus]) {
                    vis_routes[bus] = true;
                    for (int nxt : routes[bus]) {
                        if (nxt == target) { ans = buses + 1; break; }
                        if (!vis_stops.count(nxt)) {
                            vis_stops.insert(nxt);
                            q.push({nxt, buses + 1});
                        }
                    }
                }
                if (ans != -1) break;
            }
            if (ans != -1) break;
        }
        std::cout << ans << std::endl;
    }
    return 0;
}