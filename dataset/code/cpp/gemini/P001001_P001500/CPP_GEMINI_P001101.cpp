#include <vector>
#include <numeric>

class Solution {
    int findSet(std::vector<int>& parent, int i) {
        if (parent[i] == i) return i;
        return parent[i] = findSet(parent, parent[i]);
    }
public:
    std::vector<int> findRedundantConnection(std::vector<std::vector<int>>& edges) {
        int n = edges.size() + 1;
        std::vector<int> parent(n);
        std::iota(parent.begin(), parent.end(), 0);

        for (const auto& e : edges) {
            int ru = findSet(parent, e[0]), rv = findSet(parent, e[1]);
            if (ru == rv) return e;
            parent[ru] = rv;
        }
        return {};
    }
};