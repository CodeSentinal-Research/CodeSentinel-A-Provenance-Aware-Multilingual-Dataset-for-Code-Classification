#include <vector>

class Solution {
    void dfs(int node, int target, const std::vector<std::vector<int>>& graph, std::vector<int>& path, std::vector<std::vector<int>>& res) {
        if (node == target) {
            res.push_back(path);
            return;
        }
        for (int next : graph[node]) {
            path.push_back(next);
            dfs(next, target, graph, path, res);
            path.pop_back();
        }
    }
public:
    std::vector<std::vector<int>> allPathsSourceTarget(std::vector<std::vector<int>>& graph) {
        std::vector<std::vector<int>> res;
        std::vector<int> path = {0};
        dfs(0, graph.size() - 1, graph, path, res);
        return res;
    }
};