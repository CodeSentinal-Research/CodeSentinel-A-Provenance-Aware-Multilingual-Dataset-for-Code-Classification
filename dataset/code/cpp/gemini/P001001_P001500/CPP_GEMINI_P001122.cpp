#include <vector>

class Solution {
    bool dfs(int u, const std::vector<std::vector<int>>& graph, std::vector<int>& color) {
        color[u] = 1;
        for (int v : graph[u]) {
            if (color[v] == 1 || (color[v] == 0 && !dfs(v, graph, color))) return false;
        }
        color[u] = 2;
        return true;
    }
public:
    std::vector<int> eventualSafeNodes(std::vector<std::vector<int>>& graph) {
        int n = graph.size();
        std::vector<int> color(n, 0);
        std::vector<int> res;
        for (int i = 0; i < n; i++) {
            if (color[i] == 2 || (color[i] == 0 && dfs(i, graph, color))) {
                res.push_back(i);
            }
        }
        return res;
    }
};