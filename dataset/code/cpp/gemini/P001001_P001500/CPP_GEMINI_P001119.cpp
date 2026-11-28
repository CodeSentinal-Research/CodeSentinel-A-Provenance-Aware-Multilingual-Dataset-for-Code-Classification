#include <vector>
#include <string>
#include <unordered_map>
#include <queue>

class Solution {
public:
    std::vector<double> calcEquation(std::vector<std::vector<std::string>>& equations, std::vector<double>& values, std::vector<std::vector<std::string>>& queries) {
        std::unordered_map<std::string, std::unordered_map<std::string, double>> graph;
        for (size_t i = 0; i < equations.size(); i++) {
            const auto& a = equations[i][0];
            const auto& b = equations[i][1];
            double val = values[i];
            graph[a][b] = val;
            graph[b][a] = 1.0 / val;
        }
        std::vector<double> res;
        for (const auto& q : queries) {
            const auto& src = q[0];
            const auto& dst = q[1];
            if (!graph.count(src) || !graph.count(dst)) {
                res.push_back(-1.0);
            } else if (src == dst) {
                res.push_back(1.0);
            } else {
                std::queue<std::pair<std::string, double>> queue;
                queue.push({src, 1.0});
                std::unordered_set<std::string> visited = {src};
                double ans = -1.0;
                while (!queue.empty()) {
                    auto [node, prod] = queue.front();
                    queue.pop();
                    if (node == dst) { ans = prod; break; }
                    for (const auto& [nxt, weight] : graph[node]) {
                        if (!visited.count(nxt)) {
                            visited.insert(nxt);
                            queue.push({nxt, prod * weight});
                        }
                    }
                }
                res.push_back(ans);
            }
        }
        return res;
    }
};