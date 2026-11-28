#include <vector>
#include <numeric>

class Solution {
    int findSet(std::vector<int>& parent, int i) {
        if (parent[i] == i) return i;
        return parent[i] = findSet(parent, parent[i]);
    }
public:
    int findCircleNum(std::vector<std::vector<int>>& isConnected) {
        int n = isConnected.size();
        std::vector<int> parent(n);
        std::iota(parent.begin(), parent.end(), 0);
        int provinces = n;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (isConnected[i][j]) {
                    int ri = findSet(parent, i), rj = findSet(parent, j);
                    if (ri != rj) {
                        parent[ri] = rj;
                        provinces--;
                    }
                }
            }
        }
        return provinces;
    }
};