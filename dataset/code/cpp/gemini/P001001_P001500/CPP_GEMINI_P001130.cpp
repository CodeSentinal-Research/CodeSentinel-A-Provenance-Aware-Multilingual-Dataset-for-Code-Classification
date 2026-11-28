#include <vector>
#include <string>
#include <numeric>

class Solution {
    int findSet(std::vector<int>& parent, int i) {
        if (parent[i] == i) return i;
        return parent[i] = findSet(parent, parent[i]);
    }
    void unionSet(std::vector<int>& parent, int i, int j) {
        int ri = findSet(parent, i), rj = findSet(parent, j);
        if (ri != rj) parent[ri] = rj;
    }
public:
    int regionsBySlashes(std::vector<std::string>& grid) {
        int n = grid.size();
        std::vector<int> parent(4 * n * n);
        std::iota(parent.begin(), parent.end(), 0);

        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {
                int root = 4 * (r * n + c);
                char val = grid[r][c];
                if (val != '/') {
                    unionSet(parent, root + 0, root + 1);
                    unionSet(parent, root + 2, root + 3);
                }
                if (val != '\\') {
                    unionSet(parent, root + 0, root + 3);
                    unionSet(parent, root + 1, root + 2);
                }
                if (r + 1 < n) {
                    unionSet(parent, root + 2, 4 * ((r + 1) * n + c) + 0);
                }
                if (c + 1 < n) {
                    unionSet(parent, root + 1, 4 * (r * n + c + 1) + 3);
                }
            }
        }

        int count = 0;
        for (int i = 0; i < 4 * n * n; i++) {
            if (findSet(parent, i) == i) count++;
        }
        return count;
    }
};