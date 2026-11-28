#include <vector>
#include <queue>
#include <unordered_set>

class Solution {
public:
    std::vector<int> findMinHeightTrees(int n, std::vector<std::vector<int>>& edges) {
        if (n <= 2) {
            std::vector<int> res(n);
            for (int i = 0; i < n; i++) res[i] = i;
            return res;
        }
        std::vector<std::unordered_set<int>> adj(n);
        for (const auto& e : edges) {
            adj[e[0]].insert(e[1]);
            adj[e[1]].insert(e[0]);
        }
        std::queue<int> leaves;
        for (int i = 0; i < n; i++) {
            if (adj[i].size() == 1) leaves.push(i);
        }
        int remaining = n;
        while (remaining > 2) {
            int count = leaves.size();
            remaining -= count;
            for (int i = 0; i < count; i++) {
                int leaf = leaves.front();
                leaves.pop();
                int neighbor = *adj[leaf].begin();
                adj[neighbor].erase(leaf);
                if (adj[neighbor].size() == 1) leaves.push(neighbor);
            }
        }
        std::vector<int> res;
        while (!leaves.empty()) {
            res.push_back(leaves.front());
            leaves.pop();
        }
        return res;
    }
};